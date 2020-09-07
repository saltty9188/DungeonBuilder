#include "lockeddoor.h"

using namespace core::dungeon::common;


LockedDoor::LockedDoor(): Doorway{} {

}

std::string LockedDoor::description() const {
    return "a Locked Door to another chamber.";
}

char LockedDoor::displayCharacter() const {
    return '@';
}
