#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include "../room.h"

namespace core::dungeon::basic {
    /**
     * @brief The RockChamber class is a rock chamber Room exclusive to BasicDungeonLevel.
     */
    class RockChamber : public Room
    {
    public:
        /**
         * @brief The constructor for RockChamber that accepts the integer ID of the Room and sets all the RoomEdge to RockWall.
         * @param id The ID of the Room.
         */
        RockChamber(int id);
        virtual ~RockChamber() = default;

        /**
         * @brief Returns a description of this Room, its Item and Creature and its RoomEdges.
         * @return A description of this Room, its Item and Creature and its RoomEdges.
         */
        virtual std::string description() const override;
    };
}


#endif // ROCKCHAMBER_H
