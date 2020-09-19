#include "magicaldungeonlevel.h"

using namespace core::dungeon::magical;


MagicalDungeonLevel::MagicalDungeonLevel(const std::string &name, int width, int height): DungeonLevel{name, width, height} {

}

std::string MagicalDungeonLevel::description() const {
    std::string description{name()};

    description.append("\nSize: ");
    description.push_back('0' + char(width()));
    description.append(" x ");
    description.push_back('0' + char(height()));

    description.append("\nType: Magical Labyrinth (Magical Dungeon)");
    return description;
}
