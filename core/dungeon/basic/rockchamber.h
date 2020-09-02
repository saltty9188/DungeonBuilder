#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include "../room.h"

namespace core::dungeon::basic {
class RockChamber : public Room
{
public:
    RockChamber(int id);
    virtual ~RockChamber() = default;
    virtual std::string description() const override;
};
}


#endif // ROCKCHAMBER_H
