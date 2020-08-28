#include "opendoorway.h"
#include "../room.h"

using namespace core::dungeon::common;

OpenDoorway::OpenDoorway(): Doorway{}
{

}

/**
 * @brief Returns the description of this doorway.
 * @return Returns the description of this doorway.
 */
std::string OpenDoorway::description() const {
    return "an Open Doorway to another chamber.";
}

/**
 * @brief Returns the character displayed in the dungeon view output.
 *
 * The character returned by this function is dependant on the direction
 * in the parent Room that this doorway occupies.
 *
 * @return The character displayed in the dungeon view output.
 */
char OpenDoorway::displayCharacter() const {
    switch(direction()) {
    case Room::Direction::North:
        return '^';

    case Room::Direction::East:
        return '>';

    case Room::Direction::South:
        return 'v';

    case Room::Direction::West:
        return '<';
    }
    return ' ';
}

bool OpenDoorway::isPassage() const {
    return true;
}
