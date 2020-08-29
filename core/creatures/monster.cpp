#include "monster.h"
using namespace core::creatures;

Monster::Monster(std::string name): AbstractCreature{name}
{

}

/**
 * @brief Returns a deap-copy clone of this Monster.
 * @return A deap-copy clone of this Monster.
 */
std::shared_ptr<AbstractCreature> Monster::clone() const {
    return std::make_shared<Monster>(name());
}
