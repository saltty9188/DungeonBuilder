#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <array>
#include <memory>
#include "roomedge.h"

namespace core::dungeon {
    class Room
    {
    public:
        Room(int id);
        ~Room() = default;
       // virtual std::string description() const = 0;
        std::vector<std::string> display() const;
        int id() const;
        //item and setItem
        //creature and setCreature
        enum class Direction {North, South, East, West};
        void setEdge(const Direction &direction, RoomEdge &roomEdge);
        Direction getDirection(const RoomEdge &roomEdge) const;

        std::array<std::unique_ptr<RoomEdge>, 4> _edges;
    private:
        int _id;

    };
}


#endif // ROOM_H
