#include "roomedge.h"
#include "room.h"

using namespace core::dungeon;

RoomEdge::RoomEdge(Room &parent): _parent{&parent}
{

}

std::shared_ptr<Room> RoomEdge::parent() const {
    return _parent;
}

