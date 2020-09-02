#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

namespace core::items {
    class Item
    {
    public:
        Item(const std::string &name);
        virtual ~Item() = default;

        virtual std::shared_ptr<Item> clone() const = 0;
        std::string name() const;
        char displayCharacter() const;

    private:
        std::string _name;
    };
}

#endif // ITEM_H
