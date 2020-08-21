#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>

namespace core {


    class MenuInterface
    {
    public:
        MenuInterface(std::ostream &display, std::istream &input);
        void displayWelcome(const std::string author, const std::string title) const;
        void run();

    private:
        std::ostream &_display;
        std::istream &_input;
    };
}

#endif // MENUINTERFACE_H
