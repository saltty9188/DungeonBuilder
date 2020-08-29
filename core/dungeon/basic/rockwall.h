#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "../wall.h"

namespace core::dungeon::basic {
    class RockWall : public Wall
    {
    public:
        RockWall();
        virtual ~RockWall() = default;
        virtual std::string description() const override;
    };
}


#endif // ROCKWALL_H
