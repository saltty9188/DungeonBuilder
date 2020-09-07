#include "consumable.h"

using namespace core::items;

Consumable::Consumable(const std::string &name): Item{name} {

}

std::shared_ptr<Item> Consumable::clone() const {
    return std::make_shared<Consumable>(name());
}
