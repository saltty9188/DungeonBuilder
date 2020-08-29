#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include "../doorway.h"

namespace core::dungeon::common {
    class OpenDoorway : public Doorway
    {
    public:
        OpenDoorway();
        virtual ~OpenDoorway() = default;
        virtual std::string description() const override;
        virtual char displayCharacter() const override;
    };
}


#endif // OPENDOORWAY_H
