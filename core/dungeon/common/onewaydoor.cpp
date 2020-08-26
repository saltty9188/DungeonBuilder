#include "onewaydoor.h"
#include "../room.h"

using namespace core::dungeon::common;

OneWayDoor::OneWayDoor(Room &parent): Doorway{parent}
{

}

std::string OneWayDoor::description() const {

    Room::Direction direction{parent()->getDirection(*this)};

    switch(direction) {
    case Room::Direction::North:

        return "To the NORTH is an Exit (One-Way Door) from another chamber.";

    case Room::Direction::East:

        return "To the EAST is an Exit (One-Way Door) from another chamber.";

    case Room::Direction::South:

        return "To the SOUTH is an Exit (One-Way Door) from another chamber.";

    case Room::Direction::West:

        return "To the WEST is an Exit (One-Way Door) from another chamber.";
    }

    return "";
}

char OneWayDoor::displayCharacter() const {
    return 'c';
}

bool OneWayDoor::isPassage() const {
    return false;
}
