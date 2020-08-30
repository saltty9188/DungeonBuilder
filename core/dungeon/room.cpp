#include "common/onewaydoor.h"
#include <iostream>

using namespace core::dungeon;

Room::Room(int id): _id{id}, _edges{}
{

}

/**
 * @brief Returns the item contained within this room.
 * @return The item contained within this room.
 */
std::shared_ptr<Item> Room::item() const {
    return _item;
}

/**
 * @brief Sets the Item contained within this Room to be the given Item.
 * @param newItem The Item to be put in this Room.
 */
void Room::setItem(std::shared_ptr<Item> newItem) {
    _item = newItem;
}

/**
 * @brief Returns the Creature contained within this room.
 * @return The Creature contained within this room.
 */
std::shared_ptr<AbstractCreature> Room::creature() const {
    return _creature;
}

/**
 * @brief Sets the Creature contained within this Room to be the given Creature.
 * @param newCreature The Creature to be put in this Room.
 */
void Room::setCreature(std::shared_ptr<AbstractCreature> newCreature) {
    _creature = newCreature;
}

bool Room::hasExit() const {
    for (auto edge : _edges) {
        if(edge->isPassage()) {
            std::shared_ptr<Doorway> temp = std::dynamic_pointer_cast<Doorway>(edge);
            if(temp->isExit()) {
                return true;
            }
        }
    }
    return false;
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

    returnArray[2].push_back((creature() ? 'M' : ' '));
    returnArray[2].push_back((hasExit() ? '*' : ' '));
    returnArray[2].push_back((item() ? 'L' : ' '));

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

/**
 * @brief Returns the opposite direction to the Direction supplied.
 * @param direction The Direction to get the opposite of.
 * @return The opposite direction to the Direction supplied.
 */
Room::Direction Room::oppositeDirection(const Direction &direction) {
    switch(direction) {
    case Room::Direction::North:
        return Room::Direction::South;

    case Room::Direction::South:
        return Room::Direction::North;

    case Room::Direction::East:
        return Room::Direction::West;

    case Room::Direction::West:
        return Room::Direction::East;
    }
}

std::ostream& core::dungeon::operator<< (std::ostream &out, const Room &room) {
    out << room.description() << std::endl;
    return out;
}
