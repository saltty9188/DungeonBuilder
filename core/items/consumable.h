#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

namespace core::items {
    /**
     * @brief The Consumable class represents a consumable Item that can be used by the player.
     */
    class Consumable : public Item
    {
    public:
        /**
         * @brief The constructor for Consumable that accepts a string containing the Consumable's name.
         * @param name The Consumable's name.
         */
        Consumable(const std::string &name);
        virtual ~Consumable() = default;

        /**
         * @brief Returns a deep-copy clone of this Consumable.
         * @return A deep-copy clone of this Consumable.
         */
        virtual std::shared_ptr<Item> clone() const override;
    };
}


#endif // CONSUMABLE_H
