#include "PhoneBook.h"

PhoneBook::PhoneBook()
    : mNumContacts( 0 ) {}

void PhoneBook::addContact() {
    static int contactIndex;

    mContacts[contactIndex].resetAllFields();
    mContacts[contactIndex].readUserInput();

    if ( contactIndex == 7 )
        contactIndex = 0;
    else
        contactIndex++;

    if ( mNumContacts < 8 )
        mNumContacts++;
}

std::string truncate( const std::string& str ) {
    if ( str.length() > 10 )
        return str.substr( 0, 9 ) + ".";
    return str;
}

void PhoneBook::displayAll() {
    std::cout << '\n';
    std::cout << std::right << std::setw( 10 ) << "Index" << '|' << std::setw( 10 ) << "First name"
              << '|' << std::setw( 10 ) << "Last name" << '|' << std::setw( 10 ) << "Nickname"
              << '\n';

    for ( int i{ 0 }; i < mNumContacts; i++ ) {
        std::cout << std::right << std::setw( 10 ) << i + 1 << '|' << std::setw( 10 )
                  << truncate( mContacts[i].getFirstName() ) << '|' << std::setw( 10 )
                  << truncate( mContacts[i].getLastName() ) << '|' << std::setw( 10 )
                  << truncate( mContacts[i].getNickname() );
        std::cout << '\n';
    }
    std::cout << '\n';
}

void trimTrailingWhitespace( std::string& str, const std::string& whitespace = " \t\n\r\f\v" ) {
    str = str.substr( 0, str.find_last_not_of( whitespace ) + 1 );
}

void PhoneBook::search() {
    if ( mNumContacts == 0 ) {
        std::cout << "No contacts in the phonebook (you can add one using ADD).\n";
        return;
    }

    displayAll();

    std::string enteredStr{ "" };
    int         enteredIndex{ 0 };
    while ( true ) {
        std::cout << "Choose an index to display contact information for (it must be among the "
                     "above-displayed indexes): ";
        if ( !( std::getline( std::cin >> std::ws, enteredStr ) ) ) {
            std::cout << "\nEOF received (or input stream error). Exiting program." << std::endl;
            std::exit( 0 );
        }

        trimTrailingWhitespace( enteredStr );

        std::stringstream ss{ enteredStr };
        if ( ss >> enteredIndex && ss.eof() ) {
            if ( ( enteredIndex < 1 || enteredIndex > mNumContacts ) )
                continue;
            else
                break;
        } else {
            enteredIndex = 0;
        }
    }

    mContacts[enteredIndex - 1].printAllFields();
}
