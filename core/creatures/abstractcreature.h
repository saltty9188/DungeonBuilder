#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {
    class AbstractCreature
    {
    public:
        AbstractCreature(std::string name);
        virtual ~AbstractCreature() = default;

        virtual std::shared_ptr<AbstractCreature> clone() = 0;
        std::string name() const;
        char displayCharacter() const;
    private:
        std::string _name;
    };
}



#endif // ABSTRACTCREATURE_H
