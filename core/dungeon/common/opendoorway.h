#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H

#include "../doorway.h"

namespace core::dungeon::common {
    /**
     * @brief The OpenDoorway class is a free Doorway to another Room.
     */
    class OpenDoorway : public Doorway
    {
    public:
        OpenDoorway();
        virtual ~OpenDoorway() = default;

        /**
         * @brief Returns the description of this Doorway.
         * @return Returns the description of this Doorway.
         */
        virtual std::string description() const override;

        /**
         * @brief Returns the character displayed in the dungeon view output.
         *
         * The character returned by this function is dependant on the direction
         * in the parent Room that this Doorway occupies.
         *
         * @return The character displayed in the dungeon view output.
         */
        virtual char displayCharacter() const override;
    };
}


#endif // OPENDOORWAY_H
