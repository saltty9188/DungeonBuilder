#include <iostream>
#include "core/menuinterface.h"
#include "core/dungeon/room.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/dungeon/basic/rockwall.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/common/onewaydoor.h"
#include "core/dungeon/common/blockeddoorway.h"
#include "core/dungeon/basic/basicdungeonlevel.h"
#include "core/dungeon/basic/basicdungeonlevelbuilder.h"
#include "core/creatures/monster.h"
#include "core/items/weapon.h"
#include "core/game.h"

using namespace std;

using namespace core::creatures;
using namespace core::items;
using namespace core::dungeon::basic;
using namespace core::dungeon::common;
using namespace core::dungeon;

int main()
{
    core::MenuInterface menuInterface{std::cout, std::cin};
    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
    menuInterface.run();

    return 0;


}
