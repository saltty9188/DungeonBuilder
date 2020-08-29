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
        virtual ~Room() = default;
        virtual std::string description() = 0;
        std::array<std::string, 5> display() const;
        int id() const;
        //item and setItem
        //creature and setCreature
        enum class Direction : unsigned {North, South, East, West};
        void setEdge(const Direction &direction, std::shared_ptr<RoomEdge> roomEdge);

    //protected:
        std::shared_ptr<RoomEdge> edge(const Direction direction);
    private:
        int _id;
        std::array<std::shared_ptr<RoomEdge>, 4> _edges;

    };
}


#endif // ROOM_H
