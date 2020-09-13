#include <iostream>
#include "core/menuinterface.h"

using namespace std;

/**
  * @file main.cpp
  * @brief The main file
  */

/**
 * @brief main Executes the Dungeon Builder application.
 * @return 0 When the program exits.
 */
int main()
{
    core::MenuInterface menuInterface{std::cout, std::cin};
    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
    menuInterface.run();

    return 0;
}
