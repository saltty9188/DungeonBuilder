#include <iostream>
#include "core/menuinterface.h"
#include "core/game.h"
#include "core/dungeon/room.h"
#include "core/dungeon/common/onewaydoor.h"

using namespace std;
using namespace core::dungeon;

int main()
{
    core::MenuInterface menuInterface{std::cout, std::cin};
    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
    menuInterface.run();

    return 0;


}
