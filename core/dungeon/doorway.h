#ifndef DOORWAY_H
#define DOORWAY_H

#include "roomedge.h"

namespace core::dungeon {
    class Doorway : public RoomEdge
    {
    public:
        Doorway();
        virtual ~Doorway();
        void connect(Doorway &oppositeDoor);
        bool isEntrance();
        bool isExit();
        void setAsEntrance();
        void setAsExit();
        virtual bool isPassage() const override;
    private:
        Doorway * _opposite;
        bool _entrance;
        bool _exit;
    };
}


#endif // DOORWAY_H
