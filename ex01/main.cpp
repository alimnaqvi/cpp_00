#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>
#include <string>

// void    promptUserNonEmpty(std::string& promptStr, std::string& userInput) {
//     std::cout << promptStr;
//     std::cin >> userInput;
// }

int main(int argc, char **argv) {
    if (argc != 1) {
        std::cout << "The program does not accept any arguments." << std::endl;
        return 1;
    }
    (void)argv;

    std::string userInput;
    while (1) {
        PhoneBook phonebook;
        while (userInput != "ADD" && userInput != "SEARCH" && userInput != "EXIT") {
            std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
            std::cin >> userInput;
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
