#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <cstdlib>

class Contact {
  public:
    Contact();
    void               resetAllFields();
    void               printAllFields();
    void               readUserInput();
    const std::string& getFirstName();
    const std::string& getLastName();
    const std::string& getNickname();
    const std::string& getPhoneNumber();
    const std::string& getDarkestSecret();

  private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickname;
    std::string mPhoneNumber;
    std::string mDarkestSecret;
};

#endif
