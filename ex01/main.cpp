#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 1) {
        std::cout << "The program does not accept any arguments." << std::endl;
        return 1;
    }
    (void)argv;

    std::string userInput;
    PhoneBook phonebook;
    while (true) {
        while (userInput != "ADD" && userInput != "SEARCH" && userInput != "EXIT") {
            std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
            if (!std::getline(std::cin >> std::ws, userInput)) {
                std::cout << "\nEOF received (or input stream error). Exiting program." << std::endl;
                return 0;
            };
        }
        if (userInput == "ADD")
            phonebook.addContact();
        else if (userInput == "SEARCH")
            phonebook.search();
        else if (userInput == "EXIT")
            break;
        else {
            std::cout << "An error occurred." << std::endl;
            return 1;
        }
        userInput = "";
    }

    return 0;
}
