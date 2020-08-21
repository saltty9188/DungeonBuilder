#include "menuinterface.h"

using namespace core;


MenuInterface::MenuInterface(std::ostream &display, std::istream &input): _display{display}, _input{input} {

}

void MenuInterface::displayWelcome(const std::string author, const std::string title) const{
    _display << "Welcome to: " << title << std::endl;
    _display << "\t\tDeveloped by " << author << std::endl;
    _display << "COMP 3023 Software Development with C++" << std::endl;
}

