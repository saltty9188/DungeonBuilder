#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>
#include "room.h"

namespace core::dungeon {
    class RoomEdge
    {
    public:
        RoomEdge();
        virtual ~RoomEdge() = default;
        virtual std::string description() const = 0;
        virtual char displayCharacter() const = 0;
        virtual bool isPassage() const = 0;
        void setDirection(const Room::Direction &direction);
    protected:
        Room::Direction direction() const;
    private:
        Room::Direction _direction;
    };
}

#endif // ROOMEDGE_H
