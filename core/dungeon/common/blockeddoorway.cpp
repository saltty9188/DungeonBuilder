#include "blockeddoorway.h"

using namespace core::dungeon::common;

BlockedDoorway::BlockedDoorway(): Doorway{} {

}

std::string BlockedDoorway::description() const {
    return "a Blocked Doorway connected to another chamber.";
}

char BlockedDoorway::displayCharacter() const {
    return 'X';
}
