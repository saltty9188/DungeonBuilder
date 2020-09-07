#include "item.h"

using namespace core::items;

Item::Item(const std::string &name): _name{name} {

}

std::string Item::name() const {
    return _name;
}

char Item::displayCharacter() const {
    return 'L';
}

