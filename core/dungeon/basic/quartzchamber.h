#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include "../room.h"

namespace core::dungeon::basic {
    class QuartzChamber : public Room
    {
    public:
        QuartzChamber(int id);
        virtual ~QuartzChamber() = default;
        virtual std::string description() const override;
    };
}



#endif // QUARTZCHAMBER_H
