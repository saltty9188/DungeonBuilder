#include "game.h"
#include <random>
#include <ctime>
#include <iostream>

using namespace core;

// Where the class declaration includes the private data members (using class member initialisation for convenience)
std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
std::uniform_real_distribution<double> _realDistribution{0.0, 1.0}; //!< For random numbers between 0.0 & 1.0

Game::Game()
{

}

/**
 * @brief Gets the instance of the Game class.
 * @return The instance of the Game class.
 */
Game & Game::instance() {
    if(_theInstance == nullptr) {
        Game::_theInstance.reset(new Game);
    }

    return *_theInstance;
}

/**
 * @brief Returns a random double between 0.0 and 1.0.
 * @return A random double between 0.0 and 1.0.
 */
double Game::randomDouble() const{
  return _realDistribution(_randomGenerator);
}

std::unique_ptr<Game> Game::_theInstance{};


