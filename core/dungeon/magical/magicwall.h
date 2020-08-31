#ifndef MAGICWALL_H
#define MAGICWALL_H

#include "../wall.h"

namespace core::dungeon::magical {
    class MagicWall : public Wall
    {
    public:
        MagicWall();
        virtual ~MagicWall() = default;
        virtual std::string description() const override;
    };
}


#endif // MAGICWALL_H
