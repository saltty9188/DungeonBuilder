#include "consumable.h"

using namespace core::items;

Consumable::Consumable(std::string name): Item{name}
{

}

/**
 * @brief Returns a deep-copy clone of this Consumable.
 * @return A deep-copy clone of this Consumable.
 */
std::shared_ptr<Item> Consumable::clone() const {
    return std::make_shared<Consumable>(name());
}
