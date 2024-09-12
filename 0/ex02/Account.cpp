#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <time.h>
#include <ctime>
#include <string>


/*--------------------------------------------------------------*/
/*							INIT_ATRIBUTES						*/
/*--------------------------------------------------------------*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Account::Account( int initial_deposit ){
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/


void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" <<  getNbAccounts() << ";total:" << getTotalAmount() << 
	";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl; 

}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << 
	";deposit:" << deposit << ";amount:" << deposit + _amount <<
	 ";nb_deposits:" << ++_nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << 
	";withdrawal:";
	if (_amount - withdrawal < 0){
		std::cout << "refused" << std::endl;
		return(false);
	}
	std::cout << withdrawal << ";amount:" << _amount - withdrawal <<
	";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	return(true);
}

int		Account::checkAmount( void ) const{
	return(_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << 
	";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl; 
}

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

int	Account::getNbAccounts( void ){
	return(_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return(_totalAmount);
}

int	Account::getNbDeposits( void ){
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return(_totalNbWithdrawals);
}


/*--------------------------------------------------------------*/
/*							SET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Account::_displayTimestamp( void ){

	time_t	structure;
	tm		*currentTime;
	char	limitChar[16];

	time(&structure);
	currentTime = localtime(&structure);
	std::strftime(limitChar, 16, "%Y%m%d_%H%M%S", currentTime);
	std::cout << '[' << limitChar << "] ";
}