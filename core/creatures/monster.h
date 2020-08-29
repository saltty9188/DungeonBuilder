#ifndef MONSTER_H
#define MONSTER_H

#include "abstractcreature.h"

namespace core::creatures {
    class Monster : public AbstractCreature
    {
    public:
        Monster(std::string name);
        virtual ~Monster() = default;

        virtual std::shared_ptr<AbstractCreature> clone() const override;
    };
}



#endif // MONSTER_H
