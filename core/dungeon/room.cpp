#include "room.h"
#include "common/onewaydoor.h"

using namespace core::dungeon;

Room::Room(int id): _id{id}, _edges{}
{
//    for(int i = 0; i < _edges.size(); i++) {
//        _edges[i].reset(new common::OneWayDoor(*this));
//    }
}


Room::Direction Room::getDirection(const RoomEdge &roomEdge) const{
    int edgeIndex{0};

    for(int i = 0; i < _edges.size(); i++) {
        if(_edges[i].get() == &roomEdge) {
            edgeIndex = i;
        }
    }

    switch(edgeIndex) {
    case 0:
        return Room::Direction::North;

    case 1:
        return Room::Direction::East;

    case 2:
        return Room::Direction::South;

    default:
        return Room::Direction::West;
    }

}

void Room::setEdge(const Direction &direction, RoomEdge &roomEdge) {
    switch(direction) {
    case Room::Direction::North:
        _edges[0].reset(&roomEdge);
        break;

    case Room::Direction::East:
        _edges[1].reset(&roomEdge);
        break;

    case Room::Direction::South:
        _edges[2].reset(&roomEdge);
        break;

    case Room::Direction::West:
        _edges[3].reset(&roomEdge);
        break;
    }
}
