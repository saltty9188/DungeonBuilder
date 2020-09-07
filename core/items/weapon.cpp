#include "weapon.h"

using namespace core::items;

Weapon::Weapon(const std::string &name): Item{name} {

}

std::shared_ptr<Item> Weapon::clone() const {
    return std::make_shared<Weapon>(name());
}
