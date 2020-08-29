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
void Room::setEdge(const Direction &direction, std::shared_ptr<RoomEdge> roomEdge) {
    if(roomEdge) {
        roomEdge->setDirection(direction);
        switch(direction) {
        case Room::Direction::North:
            _edges[0] = roomEdge;
            break;

        case Room::Direction::East:
            _edges[1] = roomEdge;
            break;

        case Room::Direction::South:
            _edges[2] = roomEdge;
            break;

        case Room::Direction::West:
            _edges[3] = roomEdge;
            break;
        }
    }
}

/**
 * @brief Returns a shared pointer to the Room Edge at the given Direction.
 * @param direction The Direction of the Room Edge to be retrieved.
 * @return A shared pointer to the Room Edge at the given Direction.
 */
std::shared_ptr<RoomEdge> Room::edge(const Direction direction) const {
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

std::array<std::string, 5> Room::display() const {
    std::array<std::string, 5> returnArray{};
    returnArray[0] = "+----";
    returnArray[0].push_back(edge(Room::Direction::North)->displayCharacter());
    returnArray[0].append("----+");

    returnArray[1] = "|         |";

    returnArray[2].push_back(edge(Room::Direction::West)->displayCharacter());
    returnArray[2].append("   ");
    //REPLACE WITH MONSTER/ITEM STUFF
    returnArray[2].append("   ");

    returnArray[2].append("   ");
    returnArray[2].push_back(edge(Room::Direction::East)->displayCharacter());

    returnArray[3] = "|         |";

    returnArray[4] = "+----";
    returnArray[4].push_back(edge(Room::Direction::South)->displayCharacter());
    returnArray[4].append("----+");

    return returnArray;
}

int Room::id() const {
    return _id;
}

std::ostream& core::dungeon::operator<< (std::ostream &out, const Room &room) {
    out << room.description() << std::endl;
    return out;
}
