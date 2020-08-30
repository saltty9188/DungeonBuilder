#include "doorway.h"

using namespace core::dungeon;

Doorway::Doorway():RoomEdge{}, _opposite{nullptr}, _entrance{false}, _exit{false}
{

}

Doorway::~Doorway() {
    delete _opposite;
}

/**
 * @brief Returns true if this doorway is the exit to the dungeon.
 * @return True if this doorway is the exit to the dungeon.
 */
bool Doorway::isExit() const {
    return _exit;
}

/**
 * @brief Returns true if this doorway is the entrance to the dungeon.
 * @return True if this doorway is the entrance to the dungeon.
 */
bool Doorway::isEntrance() const {
    return _entrance;
}

/**
 * @brief Sets this doorway as the exit to the dungeon.
 */
void Doorway::setAsExit() {
    _exit = true;
}

/**
 * @brief Sets this doorway as the entrance to the dungeon.
 */
void Doorway::setAsEntrance() {
    _entrance = true;
}

void Doorway::connect(Doorway &oppositeDoor) {
    _opposite = &oppositeDoor;
    oppositeDoor._opposite = this;
}

bool Doorway::isPassage() const {
    return true;
}
