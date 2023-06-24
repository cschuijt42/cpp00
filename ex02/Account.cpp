#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Static definitions

int	Account::_nbAccounts         = 0;
int	Account::_totalAmount        = 0;
int	Account::_totalNbDeposits    = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor

Account::Account(int initial_deposit)
{
	_accountIndex  = Account::_nbAccounts;
	_amount        = initial_deposit;
	_nbDeposits    = 0;
	_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";"
			  << "amount:" << _amount       << ";"
			  << "created"                  << std::endl;
}

// Destructor

Account::~Account()
{
	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;

	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";"
			  << "amount:" << _amount       << ";"
			  << "closed"                  << std::endl;
}

// Class methods

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	// accounts:8;total:12442;deposits:8;withdrawals:6
	_displayTimestamp();
	std::cout << "accounts:"    << Account::_nbAccounts         << ";"
	          << "total:"       << Account::_totalAmount        << ";"
			  << "deposits:"    << Account::_totalNbDeposits    << ";"
			  << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// Instance methods

void	Account::makeDeposit(int deposit)
{
	int old_balance = _amount;
	_amount += deposit;
	_nbDeposits++;

	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:"       << _accountIndex << ";"
			  << "p_amount:"    << old_balance   << ";"
			  << "deposit:"     << deposit       << ";"
			  << "amount:"      << _amount       << ";"
			  << "nb_deposits:" << _nbDeposits   << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	old_balance = _amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:"      << _accountIndex << ";"
				  << "p_amount:"   << old_balance   << ";"
				  << "withdrawal:refused"           << std::endl;
		return false;
	}
	
	_amount -= withdrawal;
	_nbWithdrawals++;

	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	_displayTimestamp();
	std::cout << "index:"          << _accountIndex  << ";"
			  << "p_amount:"       << old_balance    << ";"
			  << "withdrawal:"     << withdrawal     << ";"
			  << "amount:"         << _amount        << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	// index:0;amount:47;deposits:1;withdrawals:0
	_displayTimestamp();

	std::cout << "index:"       << _accountIndex  << ";"
			  << "amount:"      << _amount        << ";"
			  << "deposits:"    << _nbDeposits    << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

// Utility

void	Account::_displayTimestamp()
{
	// Does not endl to ensure whatever gets printed after
	// comes out correctly. Endl in other functions!

	time_t	time = std::time(nullptr);
	tm		tm   = *std::localtime(&time);
	std::cout << std::put_time(&tm, "[%Y%m%d_%H%M%S] ");

	// Timestamp that's the same as the test file for comparison:
	// std::cout << "[19920104_091532] ";
}
