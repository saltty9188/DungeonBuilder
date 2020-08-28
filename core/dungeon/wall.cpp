#include "wall.h"

using namespace core::dungeon;

Wall::Wall()
{

}

/**
 * @brief Returns the character displayed by this wall when in the dungeon view menu.
 *
 * Character returned is determined by the direction this wall is facing within
 * its enclosing Room.
 *
 * @return The character displayed by this wall when in the dungeon view menu.
 */
char Wall::displayCharacter() const {
    switch(direction()) {
    case Room::Direction::North:
    case Room::Direction::South:
        return '-';

    case Room::Direction::East:
    case Room::Direction::West:
        return '|';
    }
}

bool Wall::isPassage() const {
    return false;
}
