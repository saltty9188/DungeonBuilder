#ifndef DOORWAY_H
#define DOORWAY_H

#include "roomedge.h"

namespace core::dungeon {
    class Doorway : public RoomEdge
    {
    public:
        /**
         * @brief The constructor for DungeonLevel accepting a string containing the name of the DungeonLevel and its width and height.
         * @param name   The name of the DungeonLevel.
         * @param width  The width of the DungeonLevel.
         * @param height The height of the DungeonLevel.
         */
        Doorway();
        virtual ~Doorway() = default;

        /**
         * @brief Returns true if this Doorway is connected to another Doorway.
         * @return True if this Doorway is connected to another Doorway, false otherwise.
         */
        virtual bool isPassage() const override;

        /**
         * @brief Connect this Doorway to the opposite Doorway
         * @param oppositeDoor The opposite Doorway.
         */
        void connect(Doorway &oppositeDoor);

        /**
         * @brief Returns true if this doorway is the entrance to the dungeon.
         * @return True if this doorway is the entrance to the dungeon.
         */
        bool isEntrance() const;

        /**
         * @brief Returns true if this doorway is the exit to the dungeon.
         * @return True if this doorway is the exit to the dungeon.
         */
        bool isExit() const;

        /**
         * @brief Sets this doorway as the entrance to the dungeon.
         */
        void setAsEntrance();

        /**
         * @brief Sets this doorway as the exit to the dungeon.
         */
        void setAsExit();
    private:
        Doorway * _opposite;
        bool _entrance;
        bool _exit;
    };
}


#endif // DOORWAY_H
