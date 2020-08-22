#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>

namespace core::dungeon {
    class RoomEdge
    {
    public:
        RoomEdge();
        virtual ~RoomEdge() = default;
        virtual std::string description() const = 0;
        virtual char displayCharacter() const = 0;
        virtual bool isPassage() const = 0;
    };
}

#endif // ROOMEDGE_H
