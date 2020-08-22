#ifndef GAME_H
#define GAME_H

#include <string>
namespace core {
    class Game
    {
    public:
        static Game * instance();

        void setDungeonType(); //add param later
        void createExampleLevel();
        void createRandomLevel(std::string name, int width, int height);
        void displayLevel();
        double randomDouble();

        Game(const Game &other) = delete;
        Game & operator=(const Game &other) = delete;
    private:
        Game();
        static Game *_theInstance;


    };
}


#endif // GAME_H
