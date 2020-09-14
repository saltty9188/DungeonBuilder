#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include "../room.h"

namespace core::dungeon::basic {
    /**
     * @brief The QuartzChamber class is a quartz chamber Room exclusive to BasicDungeonLevel.
     */
    class QuartzChamber : public Room
    {
    public:
        /**
         * @brief The constructor for QuartzChamber that accepts the integer ID of the Room and sets all the RoomEdge to RockWall.
         * @param id The ID of the Room.
         */
        QuartzChamber(int id);
        virtual ~QuartzChamber() = default;

        /**
         * @brief Returns a description of this Room, its Item and Creature and its RoomEdges.
         * @return A description of this Room, its Item and Creature and its RoomEdges.
         */
        virtual std::string description() const override;
    };
}



#endif // QUARTZCHAMBER_H
