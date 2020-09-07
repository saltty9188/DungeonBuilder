#include "wall.h"

using namespace core::dungeon;

Wall::Wall() {

}

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
