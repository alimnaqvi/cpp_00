#include "Contact.h"

Contact::Contact()
    : mFirstName("")
    , mLastName("")
    , mNickname("")
    , mPhoneNumber("")
    , mDarkestSecret("")
{}

void Contact::resetAllFields() {
    mFirstName     = "";
    mLastName      = "";
    mNickname      = "";
    mPhoneNumber   = "";
    mDarkestSecret = "";
}

void Contact::printAllFields() {
    std::cout << "First name: " << mFirstName << '\n';
    std::cout << "Last name: " << mLastName << '\n';
    std::cout << "Nickname: " << mNickname << '\n';
    std::cout << "Phone number: " << mPhoneNumber << '\n';
    std::cout << "Darkest secret: " << mDarkestSecret << '\n';
}

void getFieldInput(const std::string& prompt, std::string& field) {
    while (field == "") {
        std::cout << prompt;
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
}

const std::string& Contact::getFirstName() {
    return mFirstName;
}

const std::string& Contact::getLastName() {
    return mLastName;
}

const std::string& Contact::getNickname() {
    return mNickname;
}

const std::string& Contact::getPhoneNumber() {
    return mPhoneNumber;
}

const std::string& Contact::getDarkestSecret() {
    return mDarkestSecret;
}
