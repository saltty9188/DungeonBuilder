#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

namespace core::items {
    class Item
    {
    public:
        /**
         * @brief The constructor for Item that accepts a string containing the Item's name.
         * @param name The Item's name.
         */
        Item(const std::string &name);
        virtual ~Item() = default;

        /**
         * @brief Returns a deep-copy clone of this Item.
         * @return A deep-copy clone of this Item.
         */
        virtual std::shared_ptr<Item> clone() const = 0;

        /**
         * @brief Returns the name of this Item.
         * @return The name of this Item.
         */
        std::string name() const;

        /**
         * @brief Returns the display character for this Item in the dungeon view.
         * @return The display character for this Item.
         */
        char displayCharacter() const;

    private:
        std::string _name;
    };
}

#endif // ITEM_H
