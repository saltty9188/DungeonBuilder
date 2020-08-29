#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

namespace core::items {
    class Weapon : public Item
    {
    public:
        Weapon(std::string name);
        virtual ~Weapon() = default;

        virtual std::shared_ptr<Item> clone() const override;
    };
}



#endif // WEAPON_H
