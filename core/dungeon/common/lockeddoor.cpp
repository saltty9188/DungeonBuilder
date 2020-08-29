#include "lockeddoor.h"
#include "../room.h"

using namespace core::dungeon::common;


LockedDoor::LockedDoor(): Doorway{}
{

}

/**
 * @brief Returns the description of this doorway.
 * @return Returns the description of this doorway.
 */
std::string LockedDoor::description() const {
    return "a Locked Door to another chamber.";
}

/**
 * @brief Returns the character displayed in the dungeon view output.
 * @return The character displayed in the dungeon view output.
 */
char LockedDoor::displayCharacter() const {
    return '@';
}
