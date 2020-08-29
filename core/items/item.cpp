#include "item.h"

using namespace core::items;

Item::Item(std::string name): _name{name}
{

}

/**
 * @brief Returns the name of this Item.
 * @return The name of this Item.
 */
std::string Item::name() const {
    return _name;
}

/**
 * @brief Returns the display character for this Item in the dungeon view.
 * @return The display character for this Item.
 */
char Item::displayCharacter() const {
    return 'L';
}

