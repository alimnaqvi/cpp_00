#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <iomanip>
#include <string>
#include <sstream>

class PhoneBook {
 public:
    PhoneBook();
    void    addContact();
    void    search();
 private:
    Contact mContacts[8];
    int     mNumContacts;
    void    displayAll();
};

#endif
