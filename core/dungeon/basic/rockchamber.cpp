#include "rockchamber.h"
#include "rockwall.h"


using namespace core::dungeon::basic;


RockChamber::RockChamber(int id): Room{id} {
    // Initialise each edge to be a Rock Wall
    setEdge(Room::Direction::North, std::make_shared<RockWall>());
    setEdge(Room::Direction::East, std::make_shared<RockWall>());
    setEdge(Room::Direction::South, std::make_shared<RockWall>());
    setEdge(Room::Direction::West, std::make_shared<RockWall>());
}

std::string RockChamber::description() const {
    std::string returnString{"A dank and cold cave. (Rock Chamber)\n"};
    returnString.append("To the NORTH is " + edge(Room::Direction::North)->description() + "\n");
    returnString.append("To the EAST is " + edge(Room::Direction::East)->description() + "\n");
    returnString.append("To the SOUTH is " + edge(Room::Direction::South)->description() + "\n");
    returnString.append("To the WEST is " + edge(Room::Direction::West)->description());
    if(creature()) {
        returnString.append("\nThere is a " + creature()->name() + " to fight.");
    }
    if(item()) {
        returnString.append("\nThere is a " + item()->name() + " to pick up.");
    }

    return returnString;
}
