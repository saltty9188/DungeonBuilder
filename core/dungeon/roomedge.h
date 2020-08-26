#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>
#include <memory>

namespace core::dungeon {
    class Room;

    class RoomEdge
    {
    public:
        RoomEdge(Room &parent);
        virtual ~RoomEdge() = default;
        virtual std::string description() const = 0;
        virtual char displayCharacter() const = 0;
        virtual bool isPassage() const = 0;
    protected:
        std::shared_ptr<Room> parent() const;
    private:
        std::shared_ptr<Room> _parent;
    };
}

#endif // ROOMEDGE_H
