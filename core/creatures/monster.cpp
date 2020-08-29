#include "monster.h"
using namespace core::creatures;

Monster::Monster(std::string name): AbstractCreature{name}
{

}

std::shared_ptr<AbstractCreature> Monster::clone() const {
    return std::make_shared<Monster>(name());
}
