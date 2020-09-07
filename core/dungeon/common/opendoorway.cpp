#include "opendoorway.h"

using namespace core::dungeon::common;

OpenDoorway::OpenDoorway(): Doorway{} {

}

std::string OpenDoorway::description() const {
    return "an Open Doorway to another chamber.";
}

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
}
