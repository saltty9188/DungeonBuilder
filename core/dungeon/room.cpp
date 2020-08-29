#include "common/onewaydoor.h"
#include <iostream>

using namespace core::dungeon;

Room::Room(int id): _id{id}, _edges{}
{

}

/**
 * @brief Sets the edge at the given Direction to the given Room Edge.
 * @param direction The Direction of the edge to be set.
 * @param roomEdge  The Room Edge being set.
 */
void Room::setEdge(const Direction &direction, RoomEdge *roomEdge) {
    if(roomEdge) {
        roomEdge->setDirection(direction);
        switch(direction) {
        case Room::Direction::North:
            _edges[0].reset(roomEdge);
            break;

        case Room::Direction::East:
            _edges[1].reset(roomEdge);
            break;

        case Room::Direction::South:
            _edges[2].reset(roomEdge);
            break;

        case Room::Direction::West:
            _edges[3].reset(roomEdge);
            break;
        }
    }
}

/**
 * @brief Returns a shared pointer to the Room Edge at the given Direction.
 * @param direction The Direction of the Room Edge to be retrieved.
 * @return A shared pointer to the Room Edge at the given Direction.
 */
std::shared_ptr<RoomEdge> Room::edge(const Direction direction) {
    switch(direction) {
    case Room::Direction::North:
        return _edges[0];
        break;

    case Room::Direction::East:
        return _edges[1];
        break;

    case Room::Direction::South:
        return _edges[2];
        break;

    case Room::Direction::West:
        return _edges[3];
        break;
    }
}
