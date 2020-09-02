#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include "dungeon/dungeonlevel.h"
#include "dungeon/dungeonlevelbuilder.h"
#include "dungeon/room.h"

namespace core {
    class Game
    {
    public:
        static Game & instance();
        ~Game();
        void setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder);
        void createExampleLevel();
        void createRandomLevel(std::string name, int width, int height);
        dungeon::DungeonLevel & displayLevel() const;
        double randomDouble() const;

        Game(const Game &other) = delete;
        Game & operator=(const Game &other) = delete;
    private:
        Game();
        static std::unique_ptr<Game> _theInstance;

        dungeon::DungeonLevel *_level;
        std::unique_ptr<dungeon::DungeonLevelBuilder> _builder;
        dungeon::Room::Direction randomDirection(const std::vector<dungeon::Room::Direction> directions) const;
        bool isEdge(const dungeon::Room::Direction dungeonEdge, const dungeon::Room &room) const;
        bool isCorner(const dungeon::Room &room) const;
        bool hasExit(const dungeon::Room &room) const;
        bool hasEntrance(const dungeon::Room &room) const;
        dungeon::DungeonLevelBuilder::MoveContraints randomConstraint(bool originConstraint) const;
        int doorCount(const dungeon::Room &room, bool includeEntranceExit) const;
        std::vector<dungeon::Room::Direction> availableEdges(const dungeon::Room &room) const;
    };
}


#endif // GAME_H
