#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include <ostream>
#include "dungeon/dungeonlevel.h"
#include "dungeon/dungeonlevelbuilder.h"
#include "dungeon/room.h"

namespace core {
    class Game
    {
    public:
        /**
         * @brief Gets the instance of the Game class.
         * @return The instance of the Game class.
         */
        static Game & instance();
        ~Game();

        /**
         * @brief Sets the type of DungeonLevel to be built by the random generator..
         * @param builder The new DungeonLevelBuilder.
         */
        void setDungeonType(std::shared_ptr<dungeon::DungeonLevelBuilder> builder);

        /**
         * @brief Creates the example DungeonLevel.
         *
         * The Example DungeonLevel is a 3x3 BasicDungeonLevel with a predetermined
         * set of Doorways and Creature and Item locations.
         */
        void createExampleLevel();

        /**
         * @brief Creates a completely random DungeonLevel.
         * @param name   The name of the new DungeonLevel.
         * @param width  The width of the DungeonLevel (columns).
         * @param height The height of the DungeonLevel (rows).
         */
        void createRandomLevel(const std::string &name, int width, int height);

        /**
         * @brief Prints the graphical display of the current level to the supplied ostream object reference.
         * @param display The ostream object reference for the display to be shown to.
         */
        void displayLevel(std::ostream &display) const;

        /**
         * @brief Returns the description of the current DungeonLevel.
         * @return The description of the current DungeonLevel.
         */
        std::string levelDescription() const;

        /**
         * @brief Returns the description of the specified Room.
         * @param id The ID of the Room required.
         * @return The description of the specified Room.
         */
        std::string roomDescription(int id) const;

        /**
         * @brief Returns the number of Rooms in the current DungeonLevel.
         * @return The number of Rooms in the current DungeonLevel.
         */
        int numberOfRooms() const;

        /**
         * @brief Returns a random double between 0.0 and 1.0.
         * @return A random double between 0.0 and 1.0.
         */
        double randomDouble() const;

        Game(const Game &other) = delete;
        Game & operator=(const Game &other) = delete;
    private:
        Game();
        static std::unique_ptr<Game> _theInstance;

        dungeon::DungeonLevel *_level;
        std::shared_ptr<dungeon::DungeonLevelBuilder> _builder;
        dungeon::Room::Direction randomDirection(const std::vector<dungeon::Room::Direction> &directions) const;

        /**
         * @brief Returns whether or the supplied Room is at the edge of the Dungeon Level.
         *
         * Returns whether or the supplied Room is at the edge of the Dungeon Level. The edge of the
         * dungeon being checked is determined by the dungeonEdge parameter.
         *
         * @param dungeonEdge The edge of the dungeon being checked.
         * @param room        The Room being checked.
         * @return True if the Room is on the edge of the Dungeon, false otherwise.
         */
        bool isEdge(const dungeon::Room::Direction dungeonEdge, const dungeon::Room &room) const;
        bool isCorner(const dungeon::Room &room) const;
        bool hasExit(const dungeon::Room &room) const;
        bool hasEntrance(const dungeon::Room &room) const;

        /**
         * @brief Returns a random Move Constraint.
         * @param originConstraint Set to true if the Constraint is for the origin, constraint is
         *                         for the destination if set to false.
         * @return A random Move Constraint.
         */
        dungeon::DungeonLevelBuilder::MoveContraints randomConstraint(bool originConstraint) const;
        int doorCount(const dungeon::Room &room, bool includeEntranceExit) const;
        std::vector<dungeon::Room::Direction> availableEdges(const dungeon::Room &room) const;
    };
}


#endif // GAME_H
