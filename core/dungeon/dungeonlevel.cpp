#include "dungeonlevel.h"
#include "roomedge.h"
#include "doorway.h"
#include <iostream>

using namespace core::dungeon;

DungeonLevel::DungeonLevel(const std::string &name, int width, int height): _name{name}, _width{width}, _height{height} {

}

bool DungeonLevel::addRoom(const std::shared_ptr<Room> &room) {
    if(room) {
        _rooms.push_back(room);
        return true;
    }
    return false;
}

std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id) {
    if(id > 0 && id <= _rooms.size()) {
        return _rooms[id - 1];
    } else {
        return nullptr;
    }
}

int DungeonLevel::width() const {
    return _width;
}

int DungeonLevel::height() const {
    return _height;
}

int DungeonLevel::numberOfRooms() const {
    return _rooms.size();
}

std::string DungeonLevel::name() const {
    return _name;
}

std::vector<std::string> DungeonLevel::display() const {
    std::vector<std::string> returnVector{};

    // Get the "height" of the returned string vector
    int vectorHeight = _height * 5 + (_height - 1);
    int currentRoomRow{0};

    for(int y{0}; y < vectorHeight; y++) {
        std::string string{""};

        for(int x{0}; x < _width; x++) {
            int currentRoomIndex{x + _width * currentRoomRow};

            // Row between rooms
            if((y-5) % 6 == 0) {
                string.append("     ");
                if(std::dynamic_pointer_cast<Doorway>(_rooms[currentRoomIndex]->edge(Room::Direction::South)) &&
                        std::dynamic_pointer_cast<Doorway>(_rooms[currentRoomIndex + _width]->edge(Room::Direction::North))) {
                    string.append("|");
                } else {
                    string.append(" ");
                }
                string.append("       ");

            } else {
                // Append the current string row of the current room
                string.append(_rooms[currentRoomIndex]->display()[y - (6 * currentRoomRow)]);
                // center row of a room and we're not on the last room of a row and
                // if both rooms have connecting doors add the extra dashes
                if(((y-2) % 6 == 0) && x != _width - 1 &&
                        std::dynamic_pointer_cast<Doorway>(_rooms[currentRoomIndex]->edge(Room::Direction::East)) &&
                        std::dynamic_pointer_cast<Doorway>(_rooms[currentRoomIndex + 1]->edge(Room::Direction::West))) {
                    string.append("--");

                } else {
                    string.append("  ");
                }
            }
        }
        // Increment the row count
        if((y-5) % 6 == 0) {
            currentRoomRow++;
        }
        // Add the string to the vector
        returnVector.push_back(string);
    }

    return returnVector;
}

std::ostream& core::dungeon::operator<<(std::ostream &out, const DungeonLevel &level) {

    for (auto string : level.display()) {
        out << string << std::endl;
    }

    return out;
}
