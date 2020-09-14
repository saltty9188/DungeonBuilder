#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

namespace core::items {
    /**
     * @brief The Weapon class represents Weapons that can be found and equipped by the player.
     */
    class Weapon : public Item
    {
    public:
        /**
         * @brief The constructor for Weapon that accepts a string containing the Weapon's name.
         * @param name The Weapon's name.
         */
        Weapon(const std::string &name);
        virtual ~Weapon() = default;

        /**
         * @brief Returns a deep-copy clone of this Weapon.
         * @return A deep-copy clone of this Weapon.
         */
        virtual std::shared_ptr<Item> clone() const override;
    };
}



#endif // WEAPON_H
