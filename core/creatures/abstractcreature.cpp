#include "abstractcreature.h"

using namespace core::creatures;

AbstractCreature::AbstractCreature(std::string name): _name{name}
{

}

/**
 * @brief Returns the name of this Abstract Creature.
 * @return The name of this Abstract Creature.
 */
std::string AbstractCreature::name() const {
    return _name;
}

/**
 * @brief Returns the display character for this Abstract Creature in the dungeon view.
 * @return The display character for this Abstract Creature.
 */
char AbstractCreature::displayCharacter() const {
    return 'M';
}
