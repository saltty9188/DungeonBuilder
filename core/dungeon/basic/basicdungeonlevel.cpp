#include "basicdungeonlevel.h"
#include <string>

using namespace core::dungeon::basic;

BasicDungeonLevel::BasicDungeonLevel(const std::string &name, int width, int height): DungeonLevel{name, width, height}
{

}

/**
 * @brief A description of this Dungeon Level.
 * @return A description of this Dungeon Level.
 */
std::string BasicDungeonLevel::description() const {
    std::string description{name()};

    description.append("\nSize: ");
    description.push_back('0' + (char) width());
    description.append(" x ");
    description.push_back('0' + (char) height());

    description.append("\nType: Dark Cave (Basic Dungeon)");
    return description;
}
