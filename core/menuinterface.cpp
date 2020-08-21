#include "menuinterface.h"

using namespace core;

/**
 * @brief The constructor for MenuInterface accepting a reference to an ostream object and an istream object.
 * @param display The ostream object reference that the MenuInterface will use to display text.
 * @param input   The istream object reference that the MenuInterface will use to receive input.
 */
MenuInterface::MenuInterface(std::ostream &display, std::istream &input): _display{display}, _input{input} {

}

/**
 * @brief Displays the welcome message to the screen.
 * @param author The author of the program.
 * @param title  The title of the program.
 */
void MenuInterface::displayWelcome(const std::string author, const std::string title) const{
    _display << "Welcome to: " << title << std::endl;
    _display << "      Developed by " << author << std::endl;
    _display << "COMP 3023 Software Development with C++" << std::endl;
}

/**
 * @brief Initiates the main loop of the program.
 */
void MenuInterface::run() const{
    displayMainMenu();
}

/**
 * @brief Displays the main menu for the program.
 *
 * Displays the main menu for the program and handles user input.
 * Allows the user to generate the example dungeon, generate a random dungeon
 * or exit the program.
 * The program moves to the View Menu once a dungeon is created.
 */
void MenuInterface::displayMainMenu() const {
    // Want the menu to stay up until the user goes to another menu
    while(true) {
        // Prompt for user input
        _display << "\nWhat would you like to do?" << std::endl;
        _display << "    (g)enerate the example level" << std::endl;
        _display << "    (r)andom dungeon level" << std::endl;
        _display << "    (q)uit" << std::endl;
        std::string userInput{};
        _input >> userInput;

        switch(userInput.at(0)) {
        case 'g':
        case 'G':
            _display << "\nCreating Example Dungeon Level..." << std::endl;
            //TODO: Generate example dungeon here
            _display << "Dungeon level created!" << std::endl;
            //displayViewMenu();
            break;

        case 'r':
        case 'R':
            generateRandomDungeon();
            //displayViewMenu();
            break;

        case 'q':
        case 'Q':
            if(quitGame()) {
                return;
            }
            break;

        default:
            // Handle invalid input
            _display << "\nInvalid input. Enter a valid input." << std::endl;
        }
    }
}

/**
 * @brief Prompts the user for the parameters of a random dungeon and generates it.
 */
void MenuInterface::generateRandomDungeon() const {
    // Prompt for the user to enter the level name.
    _display << "\nWhat would you like to call the level?" << std::endl;
    std::string levelName;
    // Ignore newline character
    _input.ignore();
    std::getline (_input, levelName);

    bool selecting{true};
    int rows{0};
    // Loop the prompt for the amount of rows until the user inputs a valid number.
    while(selecting) {
        _display << "\nHow many rows in " << levelName << std::endl;
        std::string rowString{};
        _input >> rowString;

        try {
            rows = std::stoi(rowString);
            // maybe add upper limit later
            if(rows <= 0) {
                _display << "\nInvalid input. Enter an integer value." << std::endl;
            } else {
                selecting = false;
            }
        } catch (std::invalid_argument const &e) {
            _display << "\nInvalid input. Enter an integer value." << std::endl;
        }
    }

    selecting = true;
    int columns{0};
    // Loop the prompt for the amount of columns until the user inputs a valid number.
    while(selecting) {
        _display << "\nHow many columns in " << levelName << std::endl;
        std::string columnString{};
        _input >> columnString;

        try {
            columns = std::stoi(columnString);
            // maybe add upper limit later
            if(columns <= 0) {
                _display << "\nInvalid input. Enter an integer value." << std::endl;
            } else {
                selecting = false;
            }
        } catch (std::invalid_argument const &e) {
            _display << "\nInvalid input. Enter an integer value." << std::endl;
        }
    }

    selecting = true;
    while(selecting) {
        _display << "\nWhat type of dungeon level is it? (b)asic or (m)magical" << std::endl;
        std::string dungeonType{};
        _input >> dungeonType;
        switch(dungeonType.at(0)) {
        case 'B':
        case 'b':
        case 'M':
        case 'm':
            selecting = false;
            break;

        default:
            _display << "\nInvalid input. Enter a valid option." << std::endl;
        }
    }

    _display << "\nCreating " << levelName << "..." << std::endl;
    //TODO: Generate random dungeon here
    _display << "Dungeon level created!" << std::endl;

}

/**
 * @brief Displays prompt confirming the user wants to quit the game.
 * @return True if the user wishes to quit the game, false otherwise.
 */
bool MenuInterface::quitGame() const {
    // Want menu to stay looping until valid input is received
    while(true) {
        _display << "\n*Are you sure you want to quit? (y/n) *" << std::endl;
        std::string userInput{};
        _input >> userInput;
        switch(userInput.at(0)) {
        case 'y':
        case 'Y':
            _display << "\nGoodbye!" << std::endl;
            return true;

        case 'n':
        case 'N':
            return false;

        default:
            _display << "\nInvalid input, enter valid input." << std::endl;
        }
    }
}
