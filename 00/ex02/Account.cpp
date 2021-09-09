#include <iostream>
#include "Account.hpp"

#define NORM "\033[0m"
#define BLUE "\033[1;34m"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << NORM << ";";
	std::cout << "amount:" << BLUE << initial_deposit << NORM << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << NORM << ";";
	std::cout << "amount:" << BLUE << _amount << NORM << ";";
	std::cout << "closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	char buffer[18];
	time_t seconds = time(NULL);
	strftime(buffer, 18, "[%Y%m%d_%H%M%S]", localtime(&seconds));
	std::cout<< buffer;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << BLUE << _nbAccounts << NORM << ";";
	std::cout << "total:" << BLUE << _totalAmount << NORM << ";";
	std::cout << "deposits:" << BLUE << _totalNbDeposits << NORM << ";";
	std::cout << "withdrawals:" << BLUE << _totalNbWithdrawals << NORM << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << NORM << ";";
	std::cout << "p_amount:" << BLUE << _amount << NORM << ";";
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "deposit:" << BLUE << deposit << NORM << ";";
	std::cout << "amount:" << BLUE << (_amount += deposit) << NORM << ";";
	std::cout << "nb_deposits:" << BLUE << (++_nbDeposits) << NORM << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << NORM << ";";
	std::cout << "p_amount:" << BLUE << _amount << NORM << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return 0;
	}
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << BLUE << withdrawal << NORM << ";";
	std::cout << "amount:" << BLUE << (_amount -= withdrawal) << NORM << ";";
	std::cout << "nb_withdrawals:" << BLUE << (++_nbWithdrawals) << NORM << std::endl;
	return 1;
}

int Account::checkAmount(void) const
{
	if (_amount > 0)
		return _amount;
	else
		return 0;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << NORM << ";";
	std::cout << "amount:" << BLUE << _amount << NORM << ";";
	std::cout << "deposits:" << BLUE << _nbDeposits << NORM << ";";
	std::cout << "withdrawals:" << BLUE << _nbWithdrawals << NORM << std::endl;
}