#include "Harl.hpp"
#include <iostream>

Harl::Harl(){}

void	Harl::debug(void){
	std::cout << "[DEBUG]\n" << "WAHT ARE U DOING TRIYING TO DEBUG? \nYOUR CODE IS ALWAYS RIGTH THE FIRST TIME. \nPUSH IT TO PRODUCTION :)" << std::endl;
}

void	Harl::info(void){
	std::cout << "[INFO]\n" << "THE CAPITAL OF BRUNEI IS BANDAR SERI BEGAWAN" << std::endl;
}

void	Harl::warning(void){
	std::cout << "[WARNING]\n" << "DONT DRIVE WHILE DRINKING, U CAN DRINK WHILE DRIVING THO" << std::endl;
}

void	Harl::error(void){
	std::cout << "[ERROR]\n" << "IN THE DEBUG LINE THE WORD RIGTH IS SPELL WRONG" << std::endl;
}

void	Harl::complain(std::string complain)
{
	void (Harl::*function_list[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	function_names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (complain == function_names[i])
		{

			(this->*function_list[i])();
			return ;
		}
	}

	std::cout << "IDK WHAT ARE U SAYING" << std::endl;
}
