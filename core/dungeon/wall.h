#ifndef WALL_H
#define WALL_H

#include "roomedge.h"

namespace core::dungeon {
    class Wall : public RoomEdge
    {
    public:
        Wall();
        virtual ~Wall() = default;

        /**
         * @brief Returns false as a Wall is never a passage.
         * @return False.
         */
        virtual bool isPassage() const override;

        /**
         * @brief Returns the character displayed by this wall when in the dungeon view menu.
         *
         * Character returned is determined by the direction this wall is facing within
         * its enclosing Room.
         *
         * @return The character displayed by this wall when in the dungeon view menu.
         */
        virtual char displayCharacter() const override;
    };
}


#endif // WALL_H
