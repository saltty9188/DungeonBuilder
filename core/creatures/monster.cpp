#include "monster.h"
using namespace core::creatures;

Monster::Monster(const std::string &name): AbstractCreature{name}
{

}

/**
 * @brief Returns a deep-copy clone of this Monster.
 * @return A deep-copy clone of this Monster.
 */
std::shared_ptr<AbstractCreature> Monster::clone() const {
    return std::make_shared<Monster>(name());
}
