#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace core::dungeon {
    class RoomEdge;
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
        enum class Direction : unsigned {North, South, East, West};
        void setEdge(const Direction &direction, RoomEdge &roomEdge);
        std::array<std::unique_ptr<RoomEdge>, 4> _edges;
    private:
        int _id;

    };
}


#endif // ROOM_H
