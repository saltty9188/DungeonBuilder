#include "dungeonlevel.h"
#include "roomedge.h"
#include <iostream>

using namespace core::dungeon;

DungeonLevel::DungeonLevel(std::string name, int width, int height): _name{name}, _width{width}, _height{height}
{

}

/**
 * @brief Adds the given Room to the Dungeon Level.
 * @param room The Room to be added.
 * @return True if the room was successfully added, false otherwise.
 */
bool DungeonLevel::addRoom(std::shared_ptr<Room> room) {
    if(room) {
        _rooms.push_back(room);
        return true;
    }
    return false;
}

/**
 * @brief Retrieves the Room with the given ID.
 * @param id The ID of the required Room.
 * @return The required Room, or nullptr if it is not found.
 */
std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id) {
    if(id > 0 && id <= _rooms.size()) {
        return _rooms[id - 1];
    } else {
        return nullptr;
    }
}

/**
 * @brief Returns the width of this Dungeon Level.
 * @return The width of this Dungeon Level.
 */
int DungeonLevel::width() const {
    return _width;
}

/**
 * @brief Returns the height of this Dungeon Level.
 * @return The height of this Dungeon Level.
 */
int DungeonLevel::height() const {
    return _height;
}

/**
 * @brief Returns the number of rooms in this Dungeon Level.
 * @return The number of rooms in this Dungeon Level.
 */
int DungeonLevel::numberOfRooms() const {
    return _rooms.size();
}

/**
 * @brief Returns the name of this Dungeon Level.
 * @return The name of this Dungeon Level.
 */
std::string DungeonLevel::name() const {
    return _name;
}

/**
 * @brief Generates a visual display of the current Dungeon Level.
 *
 * Generate a display of the Rooms within this Dungeon Level and
 * the items/monsters within each. Connections between Doorways are
 * highlighted by dashed lines.
 *
 * @return A vector of strings holding the visual display.
 */
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
                if(_rooms[currentRoomIndex]->edge(Room::Direction::South)->isPassage() && _rooms[currentRoomIndex + _width]->edge(Room::Direction::North)->isPassage()) {
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
                        _rooms[currentRoomIndex]->edge(Room::Direction::East)->isPassage() &&
                        _rooms[currentRoomIndex + 1]->edge(Room::Direction::West)->isPassage()) {
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
