#include "weapon.h"

using namespace core::items;

Weapon::Weapon(const std::string &name): Item{name}
{

}

/**
 * @brief Returns a deep-copy clone of this Weapon.
 * @return A deep-copy clone of this Weapon.
 */
std::shared_ptr<Item> Weapon::clone() const {
    return std::make_shared<Weapon>(name());
}
