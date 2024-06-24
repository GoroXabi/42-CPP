#include "Harl.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

Harl::Harl(){

}

void	Harl::debug(void){
	std::cout << "WAHT ARE U DOING TRIYING TO DEBUG? \nYOUR CODE IS ALWAYS RIGTH THE FIRST TIME. \nPUSH IT TO PRODUCTION :)" << std::endl;
	exit(0);
}

void	Harl::info(void){
	std::cout << "THE CAPITAL OF BRUNEI IS BANDAR SERI BEGAWAN" << std::endl;
	exit(0);
}

void	Harl::warning(void){
	std::cout << "DONT DRIVE WHILE DRINKING, U CAN DRINK WHILE DRIVING THO" << std::endl;
	exit(0);
}

void	Harl::error(void){
	std::cout << "IN THE DEBUG LINE THE WORD RIGTH IS SPELL WRONG" << std::endl;
	exit(0);
}


void	Harl::complain(std::string complain)
{
	void (Harl::*function_list[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	function_names[] = {"debug", "info", "warning", "error"};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (complain == function_names[i])
			(this->*function_list[i])();
	}
	std::cout << "IDK WHAT ARE U SAYING" << std::endl;
}
