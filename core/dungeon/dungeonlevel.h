#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include <string>
#include <memory>
#include <vector>
#include "room.h"

namespace core::dungeon {
    class DungeonLevel
    {
    public:
        DungeonLevel(const std::string &name, int width, int height);
        virtual ~DungeonLevel() = default;

        /**
         * @brief Adds the given Room to the Dungeon Level.
         * @param room The Room to be added.
         * @return True if the room was successfully added, false otherwise.
         */
        bool addRoom(const std::shared_ptr<Room> &room);

        /**
         * @brief Retrieves the Room with the given ID.
         * @param id The ID of the required Room.
         * @return The required Room, or nullptr if it is not found.
         */
        std::shared_ptr<Room> retrieveRoom(int id);

        /**
         * @brief Returns the width of this Dungeon Level.
         * @return The width of this Dungeon Level.
         */
        int width() const;

        /**
         * @brief Returns the height of this Dungeon Level.
         * @return The height of this Dungeon Level.
         */
        int height() const;

        /**
         * @brief Returns the number of rooms in this Dungeon Level.
         * @return The number of rooms in this Dungeon Level.
         */
        int numberOfRooms() const;

        /**
         * @brief Returns the name of this Dungeon Level.
         * @return The name of this Dungeon Level.
         */
        std::string name() const;

        /**
         * @brief A description of this Dungeon Level.
         * @return A description of this Dungeon Level.
         */
        virtual std::string description() const = 0;

        /**
         * @brief Generates a visual display of the current Dungeon Level.
         *
         * Generate a display of the Rooms within this Dungeon Level and
         * the items/monsters within each. Connections between Doorways are
         * highlighted by dashed lines.
         *
         * @return A vector of strings holding the visual display.
         */
        std::vector<std::string> display() const; 

    private:
        std::string _name;
        int _width;
        int _height;
        std::vector<std::shared_ptr<Room>> _rooms;
    };

    /**
     * @brief Overloaded ostream out operator that displays the level map.
     * @param out The ostream object being output to.
     * @param level The level being output
     * @return The ostream object that was output to.
     */
    std::ostream& operator<<(std::ostream &out, const DungeonLevel &level);
}


#endif // DUNGEONLEVEL_H
