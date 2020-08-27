#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include "../doorway.h"

namespace core::dungeon::common {
class LockedDoor : public Doorway
{
public:
    LockedDoor(Room &parent);
    virtual ~LockedDoor() = default;
    virtual std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;
};

}

#endif // LOCKEDDOOR_H
