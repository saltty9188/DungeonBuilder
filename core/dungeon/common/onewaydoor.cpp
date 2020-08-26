#include "onewaydoor.h"

using namespace core::dungeon::common;

OneWayDoor::OneWayDoor()
{

}

std::string OneWayDoor::description() const {
    return "A door";
}

char OneWayDoor::displayCharacter() const {
    return 'c';
}

bool OneWayDoor::isPassage() const {
    return false;
}
