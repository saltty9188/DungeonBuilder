#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "../wall.h"

namespace core::dungeon::basic {
    /**
     * @brief The RockWall class represents a rock Wall exclusive to BasigDungeonLevel.
     */
    class RockWall : public Wall
    {
    public:
        RockWall();
        virtual ~RockWall() = default;

        /**
         * @brief The description of this Rock Wall.
         * @return The description of this Rock Wall.
         */
        virtual std::string description() const override;
    };
}


#endif // ROCKWALL_H
