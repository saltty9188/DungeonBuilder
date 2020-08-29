#include "rockchamber.h"
#include "../roomedge.h"
#include "rockwall.h"

#include <iostream>

using namespace core::dungeon::basic;


RockChamber::RockChamber(int id): Room{id}
{
    // Initialise each edge to be a Rock Wall
    setEdge(Room::Direction::North, new RockWall);
    setEdge(Room::Direction::East, new RockWall);
    setEdge(Room::Direction::South, new RockWall);
    setEdge(Room::Direction::West, new RockWall);
}

std::string RockChamber::description() {
    std::string returnString{"A dank and cold cave. (Rock Chamber)\n"};
    returnString.append("To the NORTH is " + edge(Room::Direction::North)->description() + "\n");
    returnString.append("To the EAST is " + edge(Room::Direction::East)->description() + "\n");
    returnString.append("To the SOUTH is " + edge(Room::Direction::South)->description() + "\n");
    returnString.append("To the WEST is " + edge(Room::Direction::West)->description());
    // Creature and item

    return returnString;
}
