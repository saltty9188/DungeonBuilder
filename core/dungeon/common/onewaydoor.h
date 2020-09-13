#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include "../doorway.h"

namespace core::dungeon::common {
    /**
     * @brief The OneWayDoor class is an exit Doorway that can only be traversed through a connect OpenDoorway or LockedDoor.
     */
    class OneWayDoor : public Doorway
    {
    public:
        OneWayDoor();
        virtual ~OneWayDoor() = default;

        /**
         * @brief Returns the description of this doorway.
         * @return Returns the description of this doorway.
         */
        virtual std::string description() const override;

        /**
         * @brief Returns the character displayed in the dungeon view output.
         *
         * The character returned by this function is dependant on the direction
         * in the parent Room that this doorway occupies.
         *
         * @return The character displayed in the dungeon view output.
         */
        virtual char displayCharacter() const override;
    };
}


#endif // ONEWAYDOOR_H
