#include "quartzchamber.h"
#include "rockwall.h"
#include "../roomedge.h"

using namespace core::dungeon::basic;

QuartzChamber::QuartzChamber(int id): Room{id}
{
    // Initialise each edge to be a Rock Wall
    setEdge(Room::Direction::North, std::make_shared<RockWall>());
    setEdge(Room::Direction::East, std::make_shared<RockWall>());
    setEdge(Room::Direction::South, std::make_shared<RockWall>());
    setEdge(Room::Direction::West, std::make_shared<RockWall>());
}

std::string QuartzChamber::description() const {

    std::string returnString{"A beautifully crystalline chamber illuminated by the light of your torch. (Quartz Chamber)\n"};
    returnString.append("To the NORTH is " + edge(Room::Direction::North)->description() + "\n");
    returnString.append("To the EAST is " + edge(Room::Direction::East)->description() + "\n");
    returnString.append("To the SOUTH is " + edge(Room::Direction::South)->description() + "\n");
    returnString.append("To the WEST is " + edge(Room::Direction::West)->description());
    // Creature and item

    return returnString;
}
