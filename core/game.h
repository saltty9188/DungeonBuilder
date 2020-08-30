#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include "dungeon/dungeonlevel.h"
#include "dungeon/dungeonlevelbuilder.h"

namespace core {
    class Game
    {
    public:
        static Game & instance();
        ~Game();
        void setDungeonType(); //add param later
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

    };
}


#endif // GAME_H
