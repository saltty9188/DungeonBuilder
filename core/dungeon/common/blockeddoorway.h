#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "../doorway.h"

namespace core::dungeon::common {
    /**
     * @brief The BlockedDoorway class is a Doorway that has collapsed and is impassable.
     */
    class BlockedDoorway : public Doorway
    {
    public:
        BlockedDoorway();
        virtual ~BlockedDoorway() = default;

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

#endif // BLOCKEDDOORWAY_H
