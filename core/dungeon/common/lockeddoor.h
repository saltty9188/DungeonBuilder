#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H

#include "../doorway.h"

namespace core::dungeon::common {
    /**
     * @brief The LockedDoor class is a Doorway that requires a key to be opened.
     */
    class LockedDoor : public Doorway
    {
    public:
        LockedDoor();
        virtual ~LockedDoor() = default;

        /**
         * @brief Returns the description of this Doorway.
         * @return Returns the description of this Doorway.
         */
        virtual std::string description() const override;

        /**
         * @brief Returns the character displayed in the dungeon view output.
         * @return The character displayed in the dungeon view output.
         */
        virtual char displayCharacter() const override;
    };
}

#endif // LOCKEDDOOR_H
