#include "abstractcreature.h"

using namespace core::creatures;

AbstractCreature::AbstractCreature(const std::string &name): _name{name} {

}

std::string AbstractCreature::name() const {
    return _name;
}

char AbstractCreature::displayCharacter() const {
    return 'M';
}
