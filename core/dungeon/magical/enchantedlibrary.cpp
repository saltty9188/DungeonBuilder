#include "enchantedlibrary.h"
#include "magicwall.h"

using namespace core::dungeon::magical;

EnchantedLibrary::EnchantedLibrary(int id): Room{id} {
    // Initialise each edge to be a Magic Wall
    setEdge(Room::Direction::North, std::make_shared<MagicWall>());
    setEdge(Room::Direction::East, std::make_shared<MagicWall>());
    setEdge(Room::Direction::South, std::make_shared<MagicWall>());
    setEdge(Room::Direction::West, std::make_shared<MagicWall>());
}

std::string EnchantedLibrary::description() const {
    std::string returnString{"A giant library filled with dusty tomes. (Enchanted Library)\n"};
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
