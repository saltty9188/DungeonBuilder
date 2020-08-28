#include "common/onewaydoor.h"

using namespace core::dungeon;

Room::Room(int id): _id{id}, _edges{}
{

}

void Room::setEdge(const Direction &direction, RoomEdge &roomEdge) {
    roomEdge.setDirection(direction);
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
