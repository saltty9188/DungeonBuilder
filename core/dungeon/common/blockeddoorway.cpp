#include "blockeddoorway.h"

using namespace core::dungeon::common;

BlockedDoorway::BlockedDoorway(): Doorway{}
{

}

/**
 * @brief Returns the description of this doorway.
 * @return Returns the description of this doorway.
 */
std::string BlockedDoorway::description() const {
    return "a Blocked Doorway connected to another chamber.";
}

/**
 * @brief Returns the character displayed in the dungeon view output.
 * @return The character displayed in the dungeon view output.
 */
char BlockedDoorway::displayCharacter() const {
    return 'X';
}

bool BlockedDoorway::isPassage() const {
    return false;
}
