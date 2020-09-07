#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "../doorway.h"

namespace core::dungeon::common {
    class BlockedDoorway : public Doorway
    {
    public:
        BlockedDoorway();
        virtual ~BlockedDoorway() = default;

        /**
         * @brief Returns the description of this doorway.
         * @return Returns the description of this doorway.
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
