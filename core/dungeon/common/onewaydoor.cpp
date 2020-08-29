#include "onewaydoor.h"
#include "../room.h"

using namespace core::dungeon::common;

OneWayDoor::OneWayDoor(): Doorway{}
{

}

/**
 * @brief Returns the description of this doorway.
 * @return Returns the description of this doorway.
 */
std::string OneWayDoor::description() const {
    return "an exit (One-Way Door) from another chamber.";
}

/**
 * @brief Returns the character displayed in the dungeon view output.
 *
 * The character returned by this function is dependant on the direction
 * in the parent Room that this doorway occupies.
 *
 * @return The character displayed in the dungeon view output.
 */
char OneWayDoor::displayCharacter() const {
    switch(direction()) {
    case Room::Direction::North:
        return 'v';

    case Room::Direction::East:
        return '<';

    case Room::Direction::South:
        return '^';

    case Room::Direction::West:
        return '>';
    }
}

