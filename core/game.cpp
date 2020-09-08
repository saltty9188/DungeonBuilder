#include "game.h"
#include <random>
#include <ctime>
#include "dungeon/room.h"
#include "dungeon/roomedge.h"
#include "dungeon/doorway.h"
#include "dungeon/basic/basicdungeonlevelbuilder.h"
#include "dungeon/magical/magicaldungeonlevelbuilder.h"


using namespace core;
using namespace core::dungeon;

// Where the class declaration includes the private data members (using class member initialisation for convenience)
std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
std::uniform_real_distribution<double> _realDistribution{0.0, 1.0}; //!< For random numbers between 0.0 & 1.0

Game::Game(): _level{nullptr}, _builder{nullptr} {

}

Game::~Game() {

}

Game & Game::instance() {
    if(_theInstance == nullptr) {
        Game::_theInstance.reset(new Game);
    }

    return *_theInstance;
}

void Game::setDungeonType(std::unique_ptr<core::dungeon::DungeonLevelBuilder> builder) {
    _builder = std::move(builder);
}

void Game::createExampleLevel() {
    _builder = std::make_unique<basic::BasicDungeonLevelBuilder>();

    _builder->buildDungeonLevel("Example Dungeon Level", 3, 3);
    for(int i = 1; i <= 9; i++) {
        _builder->buildRoom(i);
    }

    _builder->buildEntrance(_builder->getDungeonLevel()->retrieveRoom(1), Room::Direction::North);
    _builder->buildExit(_builder->getDungeonLevel()->retrieveRoom(9), Room::Direction::East);

    // Build the doorways
    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(1), _builder->getDungeonLevel()->retrieveRoom(4), Room::Direction::South,
                           DungeonLevelBuilder::MoveContraints::DestinationImpassable);
    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(1), _builder->getDungeonLevel()->retrieveRoom(2), Room::Direction::East,
                           DungeonLevelBuilder::MoveContraints::None);

    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(2), _builder->getDungeonLevel()->retrieveRoom(3), Room::Direction::East,
                           DungeonLevelBuilder::MoveContraints::OriginImpassable | DungeonLevelBuilder::MoveContraints::DestinationImpassable);
    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(2), _builder->getDungeonLevel()->retrieveRoom(5), Room::Direction::South,
                           DungeonLevelBuilder::MoveContraints::None);

    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(3), _builder->getDungeonLevel()->retrieveRoom(6), Room::Direction::South,
                           DungeonLevelBuilder::MoveContraints::DestinationLocked);

    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(4), _builder->getDungeonLevel()->retrieveRoom(7), Room::Direction::South,
                           DungeonLevelBuilder::MoveContraints::OriginImpassable | DungeonLevelBuilder::MoveContraints::DestinationImpassable);
    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(4), _builder->getDungeonLevel()->retrieveRoom(5), Room::Direction::East,
                           DungeonLevelBuilder::MoveContraints::DestinationImpassable);

    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(5), _builder->getDungeonLevel()->retrieveRoom(6), Room::Direction::East,
                           DungeonLevelBuilder::MoveContraints::None);
    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(5), _builder->getDungeonLevel()->retrieveRoom(8), Room::Direction::South,
                           DungeonLevelBuilder::MoveContraints::None);

    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(7), _builder->getDungeonLevel()->retrieveRoom(8), Room::Direction::East,
                           DungeonLevelBuilder::MoveContraints::OriginLocked | DungeonLevelBuilder::MoveContraints::DestinationLocked);

    _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(8), _builder->getDungeonLevel()->retrieveRoom(9), Room::Direction::East,
                           DungeonLevelBuilder::MoveContraints::None);

    _builder->buildItem(_builder->getDungeonLevel()->retrieveRoom(3));
    _builder->buildItem(_builder->getDungeonLevel()->retrieveRoom(5));
    _builder->buildItem(_builder->getDungeonLevel()->retrieveRoom(7));

    _builder->buildCreature(_builder->getDungeonLevel()->retrieveRoom(3));
    _builder->buildCreature(_builder->getDungeonLevel()->retrieveRoom(5));
    _builder->buildCreature(_builder->getDungeonLevel()->retrieveRoom(9));


    _level = _builder->getDungeonLevel();
}

void Game::createRandomLevel(const std::string &name, int width, int height) {
    // Make sure builder isn't null
    if(_builder) {
        _builder->buildDungeonLevel(name, width, height);

        for(int i = 1; i <= width * height; i++) {
            _builder->buildRoom(i);
        }

        // Add entrance and exit
        int entranceIndex{(int) (randomDouble() * width) + 1};
        std::vector<Room::Direction> allowedDirections{Room::Direction::North};
        // top left corner or top right corner
        if(isEdge(Room::Direction::West, *_builder->getDungeonLevel()->retrieveRoom(entranceIndex))) {
            allowedDirections.push_back(Room::Direction::West);
        }
        if(isEdge(Room::Direction::East, *_builder->getDungeonLevel()->retrieveRoom(entranceIndex))) {
            allowedDirections.push_back(Room::Direction::East);
        }

        _builder->buildEntrance(_builder->getDungeonLevel()->retrieveRoom(entranceIndex), randomDirection(allowedDirections));

        int exitIndex{(int) (randomDouble() * width) + (width * height - width + 1)};
        allowedDirections = {Room::Direction::South};
        // Allow east or west exits if its on one of the corners AND the entrance hasn't been placed there already
        if(isEdge(Room::Direction::West, *_builder->getDungeonLevel()->retrieveRoom(exitIndex)) &&     
                !(std::dynamic_pointer_cast<Doorway>(_builder->getDungeonLevel()->retrieveRoom(exitIndex)->edge(Room::Direction::West)))) {
            allowedDirections.push_back(Room::Direction::West);
        }
        if(isEdge(Room::Direction::East, *_builder->getDungeonLevel()->retrieveRoom(exitIndex)) &&
                  !(std::dynamic_pointer_cast<Doorway>(_builder->getDungeonLevel()->retrieveRoom(exitIndex)->edge(Room::Direction::East)))) {
            allowedDirections.push_back(Room::Direction::East);
        }

        _builder->buildExit(_builder->getDungeonLevel()->retrieveRoom(exitIndex), randomDirection(allowedDirections));

        // Add doorways, items and enemies
        for(int i = 1; i <= width * height; i++) {

            // Don't add doors to a 1x1 dungeon
            if(width > 1 || height > 1) {
                int requiredDoors{};
                allowedDirections.clear();

                // Get minimum number of doorways needed
                if(isCorner(*_builder->getDungeonLevel()->retrieveRoom(i))) {
                    requiredDoors = 1;
                } else {
                    requiredDoors = 2;
                }

                requiredDoors -= doorCount(*_builder->getDungeonLevel()->retrieveRoom(i), !isCorner(*_builder->getDungeonLevel()->retrieveRoom(i)));
                Room::Direction doorDirection{};
                while(requiredDoors > 0) {
                    doorDirection = randomDirection(availableEdges(*_builder->getDungeonLevel()->retrieveRoom(i)));
                    switch (doorDirection) {
                    case Room::Direction::North:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i - width),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;

                    case Room::Direction::East:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i + 1),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;

                    case Room::Direction::South:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i + width),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;

                    case Room::Direction::West:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i - 1),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;
                    }

                    requiredDoors--;
                }

                // 25% chance for another door and then 12% chance for a door after that (if there are available edges)
                int chanceOfNewDoor{25};
                int randomNumber{(int) (randomDouble() * 100)};
                while(randomNumber < chanceOfNewDoor && availableEdges(*_builder->getDungeonLevel()->retrieveRoom(i)).size() > 0) {
                    doorDirection = randomDirection(availableEdges(*_builder->getDungeonLevel()->retrieveRoom(i)));
                    switch (doorDirection) {
                    case Room::Direction::North:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i - width),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;

                    case Room::Direction::East:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i + 1),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;

                    case Room::Direction::South:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i + width),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;

                    case Room::Direction::West:
                        _builder->buildDoorway(_builder->getDungeonLevel()->retrieveRoom(i),
                                               _builder->getDungeonLevel()->retrieveRoom(i - 1),
                                               doorDirection, randomConstraint(true) | randomConstraint(false));
                        break;
                    }

                    chanceOfNewDoor = 12;
                    randomNumber = (int) (randomDouble() * 100);
                }
            }

            // Add items and monsters
            if(hasExit(*_builder->getDungeonLevel()->retrieveRoom(i))) {
                _builder->buildItem(_builder->getDungeonLevel()->retrieveRoom(i));
                _builder->buildCreature(_builder->getDungeonLevel()->retrieveRoom(i));

            } else if(!hasEntrance(*_builder->getDungeonLevel()->retrieveRoom(i))) {
                int randomNumber{(int)(randomDouble() * 100)};
                if(randomNumber < 25) {
                    _builder->buildCreature(_builder->getDungeonLevel()->retrieveRoom(i));
                }

                randomNumber = (int)(randomDouble() * 100);
                if(randomNumber < 35) {
                    _builder->buildItem(_builder->getDungeonLevel()->retrieveRoom(i));
                }
            }


        }
        _level = _builder->getDungeonLevel();
    }
}

Room::Direction Game::randomDirection(const std::vector<Room::Direction> &directions) const {
    int randomDirection{(int)(randomDouble() * directions.size())};
    return directions[randomDirection];
}

bool Game::isEdge(const dungeon::Room::Direction dungeonEdge, const dungeon::Room &room) const {
    int dungeonWidth = _builder->getDungeonLevel()->width();
    int dungeonHeight = _builder->getDungeonLevel()->height();

    switch (dungeonEdge) {
    case Room::Direction::North:
        if(room.id() >= 1 && room.id() <= dungeonWidth) {
            return true;
        }
        break;

    case Room::Direction::East:
        for(int i = dungeonWidth; i <= dungeonWidth * dungeonHeight; i+=dungeonWidth) {
            if(room.id() == i) {
                return true;
            }
        }
        break;

    case Room::Direction::South:
        if(room.id() >= (dungeonWidth * dungeonHeight - dungeonWidth + 1) && room.id() <= (dungeonWidth * dungeonHeight)) {
            return true;
        }
        break;

    case Room::Direction::West:
        for(int i = 1; i <= (dungeonWidth * dungeonHeight); i+=dungeonWidth) {
            if(room.id() == i) {
                return true;
            }
        }
        break;
    }
    return false;
}

bool Game::isCorner(const dungeon::Room &room) const {
    return ((isEdge(Room::Direction::North, room) && isEdge(Room::Direction::West, room)) ||
            (isEdge(Room::Direction::North, room) && isEdge(Room::Direction::East, room)) ||
            (isEdge(Room::Direction::South, room) && isEdge(Room::Direction::West, room)) ||
            (isEdge(Room::Direction::South, room) && isEdge(Room::Direction::East, room)));
}

bool Game::hasExit(const dungeon::Room &room) const {
    std::vector<Room::Direction> directions = {Room::Direction::North, Room::Direction::East, Room::Direction::South, Room::Direction::West};
    for(Room::Direction direction : directions) {
        // Cast to Doorway
        std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room.edge(direction));
        if(door && door->isExit()) {
            return true;
        }
    }
    return false;
}

bool Game::hasEntrance(const dungeon::Room &room) const {
    std::vector<Room::Direction> directions = {Room::Direction::North, Room::Direction::East, Room::Direction::South, Room::Direction::West};
    for(Room::Direction direction : directions) {
        // Cast to Doorway
        std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room.edge(direction));
        if(door && door->isEntrance()) {
            return true;
        }
    }
    return false;
}

DungeonLevelBuilder::MoveContraints Game::randomConstraint(bool originConstraint) const {
    int randomNumber{(int) (randomDouble() * 100)};
    if(randomNumber < 40) {
        return DungeonLevelBuilder::MoveContraints::None;
    } else if (randomNumber >= 40 && randomNumber < 70) {
        if(originConstraint) {
            return DungeonLevelBuilder::MoveContraints::OriginLocked;
        } else {
            return DungeonLevelBuilder::MoveContraints::DestinationLocked;
        }
    } else {
        if(originConstraint) {
            return DungeonLevelBuilder::MoveContraints::OriginImpassable;
        } else {
            return DungeonLevelBuilder::MoveContraints::DestinationImpassable;
        }
    }
}

int Game::doorCount(const dungeon::Room &room, bool includeEntranceExit) const {
    std::vector<Room::Direction> directions{Room::Direction::North, Room::Direction::East, Room::Direction::South, Room::Direction::West};
    int count{0};
    for (Room::Direction direction : directions) {
        // Cast to doorway
        std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room.edge(direction));
        // Increase count if a door is present
        if(door && (((door->isExit() || door->isEntrance()) && includeEntranceExit) ||
                    !(door->isExit() || door->isEntrance()))) {
                count++;
        }
    }

    return count;
}

std::vector<Room::Direction> Game::availableEdges(const Room &room) const {
    std::vector<Room::Direction> allDirections{Room::Direction::North, Room::Direction::East, Room::Direction::South, Room::Direction::West};
    std::vector<Room::Direction> availableDirections{};

    for(Room::Direction direction : allDirections) {
        if(!isEdge(direction, room) && !(std::dynamic_pointer_cast<Doorway>(room.edge(direction)))) {
            availableDirections.push_back(direction);
        }
    }
    return availableDirections;
}

void Game::displayLevel(std::ostream &display) const {
    display << *_level << std::endl;
}

std::string Game::levelDescription() const {
    return _level->description();
}

std::string Game::roomDescription(int id) const {
    return _level->retrieveRoom(id)->description();
}

int Game::numberOfRooms() const {
    return _level->numberOfRooms();
}

double Game::randomDouble() const{
  return _realDistribution(_randomGenerator);
}

std::unique_ptr<Game> Game::_theInstance{};


