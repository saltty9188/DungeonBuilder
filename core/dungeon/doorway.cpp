#include "doorway.h"

using namespace core::dungeon;

Doorway::Doorway(): _opposite{nullptr}, _entrance{false}, _exit{false}
{

}

Doorway::~Doorway() {
    delete _opposite;
    _opposite = nullptr;
}

/**
 * @brief Returns true if this doorway is the exit to the dungeon.
 * @return True if this doorway is the exit to the dungeon.
 */
bool Doorway::isExit() {
    return _exit;
}

/**
 * @brief Returns true if this doorway is the entrance to the dungeon.
 * @return True if this doorway is the entrance to the dungeon.
 */
bool Doorway::isEntrance() {
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