#include "onewaydoor.h"

using namespace core::dungeon::common;

OneWayDoor::OneWayDoor(): Doorway{}
{

}

/**
 * @brief Returns the description of this doorway.
 * @return Returns the description of this doorway.
 */
std::string OneWayDoor::description() const {
    if(isEntrance()) {
        return "the entrance to the dungeon.";
    } else if(isExit()) {
        return "the way out of the dungeon!";
    } else {
        return "an exit (One-Way Door) from another chamber.";
    }
}

/**
 * @brief Returns the character displayed in the dungeon view output.
 *
 * The character returned by this function is dependant on the direction
 * in the parent Room that this doorway occupies.
 *
 * @return The character displayed in the dungeon view output.
 */
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

