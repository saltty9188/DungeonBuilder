#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H

#include "../room.h"

namespace core::dungeon::magical {
    class AlchemistsLaboratory : public Room
    {
    public:
        /**
         * @brief The constructor for AlchemistsLaboratory that accepts the integer ID of the Room and sets all the RoomEdges to MagicWalls.
         * @param id The ID of the Room.
         */
        AlchemistsLaboratory(int id);
        virtual ~AlchemistsLaboratory() = default;

        /**
         * @brief Returns a description of this Room, its Item and Creature and its RoomEdges.
         * @return A description of this Room, its Item and Creature and its RoomEdges.
         */
        virtual std::string description() const override;
    };
}


#endif // ALCHEMISTSLABORATORY_H
