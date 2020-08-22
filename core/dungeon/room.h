#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "roomedge.h"

namespace core::dungeon {
    class Room
    {
    public:
        Room(int id);
        virtual ~Room() = default;
        virtual std::string description() const = 0;
        std::vector<std::string> display() const;
        int id() const;
        //item and setItem
        //creature and setCreature

        enum Direction {North, South, East, West};

    private:
        int _id;
    };
}


#endif // ROOM_H
