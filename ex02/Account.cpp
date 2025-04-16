#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();

    std::cout << "accounts:" << getNbAccounts() << ';';
    std::cout << "total:" << getTotalAmount() << ';';
    std::cout << "deposits:" << getNbDeposits() << ';';
    std::cout << "withdrawals:" << getNbWithdrawals() << '\n';
}

Account::Account( int initial_deposit )
    : _accountIndex( getNbAccounts() ), _amount( initial_deposit ), _nbDeposits( 0 ),
      _nbWithdrawals( 0 ) {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created" << '\n';

    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account() {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed" << '\n';
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';
    std::cout << "deposit:" << deposit << ';';
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';
    if ( _amount - withdrawal < 0 ) {
        std::cout << "withdrawal:" << "refused" << '\n';
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals << '\n';
    return true;
}

void Account::displayStatus( void ) const {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}

void Account::_displayTimestamp( void ) {
    struct tm datetime;
    time_t    timestamp;

    timestamp = time(NULL);
    datetime = *localtime(&timestamp);

    std::cout << '[';
    std::cout << 1900 + datetime.tm_year;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << 1 + datetime.tm_mon;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << datetime.tm_mday;
    std::cout << '_';
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << datetime.tm_hour;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << datetime.tm_min;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << datetime.tm_sec;
    std::cout << ']';
    std::cout << ' ';
}
