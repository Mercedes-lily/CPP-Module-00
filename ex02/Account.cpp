#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_nbAccounts = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900);
	if(now->tm_mon + 1 < 10)
		std::cout << "0" << (now->tm_mon + 1);
	else
		std::cout << (now->tm_mon + 1);
	if(now->tm_mday < 10)
		std::cout << "0" <<  now->tm_mday << "_";
	else
		std::cout <<  now->tm_mday << "_";
	if(now->tm_hour < 10)
		std::cout << "0" <<  now->tm_hour;
	else
		std::cout <<  now->tm_hour;
	if(now->tm_min < 10)
		std::cout << "0" <<  now->tm_min;
	else
		std::cout <<  now->tm_min;
	if(now->tm_sec < 10)
		std::cout << "0" <<  now->tm_sec;
	else
		std::cout <<  now->tm_sec;
	std::cout << "] ";

}

Account::Account( int initial_deposit) : _amount(initial_deposit)
{
	static int i = 0;
	this->_accountIndex = i;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << i << ";amount:" << initial_deposit <<";closed" << std::endl;
	i++;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << i << ";amount:" << initial_deposit <<";created" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return(Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount() <<";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (1);
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (0);
	}
}

