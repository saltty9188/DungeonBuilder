#ifndef DOORWAY_H
#define DOORWAY_H

#include "roomedge.h"

namespace core::dungeon {
    class Doorway : public RoomEdge
    {
        Doorway * _opposite;
        bool _entrance;
        bool _exit;
    public:
        Doorway();
        virtual ~Doorway();
        //void connect(Doorway oppositeDoor);
        bool isEntrance();
        bool isExit();
        void setAsEntrance();
        void setAsExit();
    };
}


#endif // DOORWAY_H
