#ifndef WALL_H
#define WALL_H

#include "roomedge.h"
namespace core::dungeon {
    class Wall : public RoomEdge
    {
    public:
        Wall();
        virtual ~Wall() = default;
        virtual bool isPassage() const override;
        virtual char displayCharacter() const override;
    };
}


#endif // WALL_H
