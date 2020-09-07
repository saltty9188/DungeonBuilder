#include "doorway.h"

using namespace core::dungeon;

Doorway::Doorway():RoomEdge{}, _opposite{nullptr}, _entrance{false}, _exit{false} {

}

bool Doorway::isPassage() const {
    return !(isExit() || isEntrance());
}

bool Doorway::isExit() const {
    return _exit;
}

bool Doorway::isEntrance() const {
    return _entrance;
}

void Doorway::setAsExit() {
    _exit = true;
}

void Doorway::setAsEntrance() {
    _entrance = true;
}

void Doorway::connect(Doorway &oppositeDoor) {
    _opposite = &oppositeDoor;
    oppositeDoor._opposite = this;
}
