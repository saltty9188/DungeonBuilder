#include "common/onewaydoor.h"
#include <iostream>

using namespace core::dungeon;

Room::Room(int id): _id{id}, _edges{} {

}

std::shared_ptr<Item> Room::item() const {
    return _item;
}

void Room::setItem(const std::shared_ptr<Item> &newItem) {
    _item = newItem;
}

std::shared_ptr<AbstractCreature> Room::creature() const {
    return _creature;
}

void Room::setCreature(const std::shared_ptr<AbstractCreature> &newCreature) {
    _creature = newCreature;
}

bool Room::hasExit() const {
    for (auto edge : _edges) {
        std::shared_ptr<Doorway> temp = std::dynamic_pointer_cast<Doorway>(edge);
        if(temp && temp->isExit()) {
            return true;
        }
    }
    return false;
}

void Room::setEdge(const Direction &direction, const std::shared_ptr<RoomEdge> &roomEdge) {
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

std::shared_ptr<RoomEdge> Room::edge(const Direction &direction) const {
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
    returnArray[2].push_back(((hasExit() && creature()) ? '*' : ' '));
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
