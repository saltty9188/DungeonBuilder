#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "../doorway.h"

namespace core::dungeon::common {
    class OpenDoorway : public Doorway
    {
    public:
        OpenDoorway(Room &parent);
        virtual ~OpenDoorway() = default;
        virtual std::string description() const override;
        virtual char displayCharacter() const override;
        virtual bool isPassage() const override;
    };
}


#endif // OPENDOORWAY_H
