#include "game.h"
#include <random>
#include <ctime>
#include "dungeon/room.h"
#include "dungeon/basic/basicdungeonlevelbuilder.h"

using namespace core;
using namespace core::dungeon;

// Where the class declaration includes the private data members (using class member initialisation for convenience)
std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
std::uniform_real_distribution<double> _realDistribution{0.0, 1.0}; //!< For random numbers between 0.0 & 1.0

Game::Game(): _level{nullptr}, _builder{nullptr}
{

}

Game::~Game() {
    delete _level;
}

/**
 * @brief Gets the instance of the Game class.
 * @return The instance of the Game class.
 */
Game & Game::instance() {
    if(_theInstance == nullptr) {
        Game::_theInstance.reset(new Game);
    }

    return *_theInstance;
}

void Game::setDungeonType() {

}

void Game::createExampleLevel() {
    _builder.release();
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


    delete _level;
    _level = _builder->getDungeonLevel();
}

DungeonLevel & Game::displayLevel() const {
    return *_level;
}

/**
 * @brief Returns a random double between 0.0 and 1.0.
 * @return A random double between 0.0 and 1.0.
 */
double Game::randomDouble() const{
  return _realDistribution(_randomGenerator);
}

std::unique_ptr<Game> Game::_theInstance{};


