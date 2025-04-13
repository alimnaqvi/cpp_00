#include "Contact.h"

Contact::Contact()
    : mFirstName("")
    , mLastName("")
    , mNickname("")
    , mPhoneNumber("")
    , mDarkestSecret("")
{}

void getFieldInput(const std::string& prompt, std::string& field) {
    std::cout << prompt;
    while (field == "") {
        if (!std::getline(std::cin >> std::ws, field)) {
            std::cout << "\nEOF received (or input stream error). Exiting program." << std::endl;
            std::exit(0);
        }
    }
}

void Contact::readUserInput() {
    getFieldInput("Enter first name: ", mFirstName);
    getFieldInput("Enter last name: ", mLastName);
    getFieldInput("Enter nickname: ", mNickname);
    getFieldInput("Enter phone number: ", mPhoneNumber);
    getFieldInput("Enter darkest secret: ", mDarkestSecret);

    // for testing
    // std::cout << "\nContact created successfully:\n";
    // printContact();
}

void Contact::printContact() {
    std::cout << "First name: " << mFirstName << '\n';
    std::cout << "Last name: " << mLastName << '\n';
    std::cout << "Nickname: " << mNickname << '\n';
    std::cout << "Phone number: " << mPhoneNumber << '\n';
    std::cout << "Darkest secret: " << mDarkestSecret << '\n';
}
