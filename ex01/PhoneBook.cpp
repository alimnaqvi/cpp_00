#include "PhoneBook.h"
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() {
    mNumContacts = 0;
}

void PhoneBook::addContact() {
    static int  contactIndex;

    mContacts[contactIndex].readUserInput();

    if (contactIndex == 7)
        contactIndex = 0;
    else
        contactIndex++;

    // increment mNumContacts here

    // For testing:
    // std::cout << "Contact created successfully as follows:\n";
    // contact.printContact();
}

std::string truncate(const std::string& str)
{
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
              << std::setw(10) << "Nickname";
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

void PhoneBook::search() {
    displayAll();
    // to be completed
}
