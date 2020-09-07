#include "onewaydoor.h"

using namespace core::dungeon::common;

OneWayDoor::OneWayDoor(): Doorway{} {

}

std::string OneWayDoor::description() const {
    if(isEntrance()) {
        return "the entrance to the dungeon.";
    } else if(isExit()) {
        return "the way out of the dungeon!";
    } else {
        return "an exit (One-Way Door) from another chamber.";
    }
}

char OneWayDoor::displayCharacter() const {
   if(isExit()) {
       return 'O';
   } else if(isEntrance()) {
       return 'I';
   } else {
       switch(direction()) {
       case Room::Direction::North:
           return 'v';

       case Room::Direction::East:
           return '<';

       case Room::Direction::South:
           return '^';

       case Room::Direction::West:
           return '>';
       }
   }
}

