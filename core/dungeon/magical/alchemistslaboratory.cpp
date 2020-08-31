#include "alchemistslaboratory.h"
#include "magicwall.h"

using namespace core::dungeon::magical;

AlchemistsLaboratory::AlchemistsLaboratory(int id): Room{id}
{
    // Initialise each edge to be a Magic Wall
    setEdge(Room::Direction::North, std::make_shared<MagicWall>());
    setEdge(Room::Direction::East, std::make_shared<MagicWall>());
    setEdge(Room::Direction::South, std::make_shared<MagicWall>());
    setEdge(Room::Direction::West, std::make_shared<MagicWall>());
}

std::string AlchemistsLaboratory::description() const {
    std::string returnString{"A sprawling laboratory that smells of plants and chemicals. (Alchemist's Laboratory)\n"};
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
