#include "roomedge.h"

using namespace core::dungeon;

RoomEdge::RoomEdge(): _direction{} {

}

void RoomEdge::setDirection(const Room::Direction &direction) {
    _direction = direction;
}

Room::Direction RoomEdge::direction() const {
    return _direction;
}

