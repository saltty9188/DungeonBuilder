#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <array>
#include <memory>
#include "../creatures/abstractcreature.h"
#include "../items/item.h"

using core::items::Item;
using core::creatures::AbstractCreature;

namespace core::dungeon {
    class RoomEdge;
    class Room
    {
    public:
        Room(int id);
        virtual ~Room() = default;

        virtual std::string description() const = 0;
        std::array<std::string, 5> display() const;
        int id() const;
        std::shared_ptr<Item> item() const;
        void setItem(const std::shared_ptr<Item> &newItem);
        std::shared_ptr<AbstractCreature> creature() const;
        void setCreature(const std::shared_ptr<AbstractCreature> &newCreature);

        enum class Direction : unsigned {North, South, East, West};
        static Direction oppositeDirection(const Direction &direction);
        void setEdge(const Direction &direction, const std::shared_ptr<RoomEdge> &roomEdge);
        std::shared_ptr<RoomEdge> edge(const Direction &direction) const;
    private:
        int _id;
        std::shared_ptr<Item> _item;
        std::shared_ptr<AbstractCreature> _creature;
        std::array<std::shared_ptr<RoomEdge>, 4> _edges;
        bool hasExit() const;

    };

    std::ostream& operator<<(std::ostream &out, const Room &room);
}


#endif // ROOM_H
