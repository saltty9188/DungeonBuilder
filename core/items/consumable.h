#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

namespace core::items {
    class Consumable : public Item
    {
    public:
        Consumable(const std::string &name);
        virtual ~Consumable() = default;

        virtual std::shared_ptr<Item> clone() const override;
    };
}


#endif // CONSUMABLE_H
