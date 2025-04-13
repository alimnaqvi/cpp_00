#include "PhoneBook.h"

PhoneBook::PhoneBook()
    : mNumContacts(0)
{}

void PhoneBook::addContact() {
    static int  contactIndex;

    mContacts[contactIndex].readUserInput();

    // For testing:
    // std::cout << "Contact created successfully at index "<< contactIndex << " as follows:\n";
    // mContacts[contactIndex].printContact();

    if (contactIndex == 7)
        contactIndex = 0;
    else
        contactIndex++;

    if (mNumContacts < 8)
        mNumContacts++;

}

std::string truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayAll() {
    std::cout << '\n';
    std::cout << std::right
              << std::setw(10) << "Index"
              << '|'
              << std::setw(10) << "First name"
              << '|'
              << std::setw(10) << "Last name"
              << '|'
              << std::setw(10) << "Nickname"
              << '\n';

    // For testing
    // std::cout << "mNumContacts is: " << mNumContacts << '\n';

    for (int i = 0; i < mNumContacts; i++) {
        std::cout << std::right
                  << std::setw(10) << i + 1
                  << '|'
                  << std::setw(10) << truncate(mContacts[i].getFirstName())
                  << '|'
                  << std::setw(10) << truncate(mContacts[i].getLastName())
                  << '|'
                  << std::setw(10) << truncate(mContacts[i].getNickname());
        std::cout << '\n';
    }
    std::cout << '\n';
}

// void ignoreLine()
// {
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }

void handleWhitespace(std::string& str, const std::string& whitespace = " \t\n\r\f\v") {
    unsigned int beginSpace ( str.find_first_of(whitespace) );

    if (beginSpace != std::string::npos) {
        std::string afterFirstWS = str.substr(beginSpace);

        if (afterFirstWS.find_first_not_of(whitespace) != std::string::npos) {
            str = "invalid";
            return;
        }
    }

    str = str.substr(0, str.find_last_not_of(whitespace) + 1);
}

void PhoneBook::search() {
    if (mNumContacts == 0) {
        std::cout << "No contacts in the phonebook (you can add one using ADD).\n";
        return;
    }

    displayAll();

    std::string enteredStr ("");
    int enteredIndex( 0 );
    while (true) {
        std::cout << "Choose an index to display contact information for (it must be among the above-displayed indexes): ";
        if (!(std::getline(std::cin >> std::ws, enteredStr))) {
            std::cout << "\nEOF received (or input stream error). Exiting program." << std::endl;
            std::exit(0);
        }

        handleWhitespace(enteredStr);

        try { enteredIndex = std::stoi(enteredStr);
        }
        catch (std::invalid_argument const&) {
            // std::cout << "Invalid argument (not an integer)." << '\n';
            enteredIndex = 0;
        }
        catch (std::out_of_range const&) {
            // std::cout << "Our of range (too big for an integer)" << '\n';
            enteredIndex = 0;
        }

        if ((enteredIndex < 1 || enteredIndex > mNumContacts))
            continue;
        else
            break;
    }

    // int enteredIndex( 0 );
    // while (enteredIndex < 1 || enteredIndex > mNumContacts) {
    //     std::cout << "Choose an index to display contact information for (it must be among the above-displayed indexes): ";
    //     std::cin >> enteredIndex;
    //     std::cin.clear();
    //     ignoreLine();
    // }

    // for testing
    // std::cout << "enteredIndex is " << enteredIndex << '\n';

    mContacts[enteredIndex - 1].printContact();
}
