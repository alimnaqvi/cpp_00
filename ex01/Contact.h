#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
 public:
    Contact();
    void                printContact();
    void                readUserInput();
    const std::string&  getFirstName() { return mFirstName; };
    const std::string&  getLastName() { return mLastName; };
    const std::string&  getNickname() { return mNickname; };
    const std::string&  getPhoneNumber() { return mPhoneNumber; };
    const std::string&  getDarkestSecret() { return mDarkestSecret; };
 private:
    std::string  mFirstName;
    std::string  mLastName;
    std::string  mNickname;
    std::string  mPhoneNumber;
    std::string  mDarkestSecret;
};

#endif
