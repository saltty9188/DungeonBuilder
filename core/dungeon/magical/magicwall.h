#ifndef MAGICWALL_H
#define MAGICWALL_H

#include "../wall.h"

namespace core::dungeon::magical {
    /**
     * @brief The MagicWall class represents a magic Wall exclusive to MagicalDungeonLevel.
     */
    class MagicWall : public Wall
    {
    public:
        MagicWall();
        virtual ~MagicWall() = default;

        /**
         * @brief Returns a description for this MagicWall.
         * @return A description for this MagicWall.
         */
        virtual std::string description() const override;
    };
}


#endif // MAGICWALL_H
