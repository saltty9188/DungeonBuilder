#include <iostream>
#include "core/menuinterface.h"

using namespace std;

using namespace core;

int main()
{
    core::MenuInterface menuInterface{std::cout, std::cin};
    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
    menuInterface.run();

    return 0;
}
