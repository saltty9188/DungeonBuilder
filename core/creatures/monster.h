#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"

namespace core::creatures {
    class Monster : public AbstractCreature
    {
    public:
        /**
         * @brief The constructor for Monster that accepts a string containing the Monster's name.
         * @param name The Monster's name.
         */
        Monster(const std::string &name);
        virtual ~Monster() = default;

        /**
         * @brief Returns a deep-copy clone of this Monster.
         * @return A deep-copy clone of this Monster.
         */
        virtual std::shared_ptr<AbstractCreature> clone() const override;
    };
}



#endif // MONSTER_H
