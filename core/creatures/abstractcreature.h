#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {
    class AbstractCreature
    {
    public:
        /**
         * @brief The constructor for AbstractCreature that accepts a string containing the Creature's name.
         * @param name The Creature's name.
         */
        AbstractCreature(const std::string &name);
        virtual ~AbstractCreature() = default;

        /**
         * @brief Returns a deep-copy clone of this AbstractCreature.
         * @return A deep-copy clone of this AbstractCreature.
         */
        virtual std::shared_ptr<AbstractCreature> clone() const = 0;

        /**
         * @brief Returns the name of this AbstractCreature.
         * @return The name of this AbstractCreature.
         */
        std::string name() const;

        /**
         * @brief Returns the display character for this AbstractCreature in the dungeon view.
         * @return The display character for this Abstract Creature.
         */
        char displayCharacter() const;
    private:
        std::string _name;
    };
}



#endif // ABSTRACTCREATURE_H
