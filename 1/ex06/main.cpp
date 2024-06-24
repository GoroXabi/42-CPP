#include <iostream>
#include "Harl.hpp"


int main(int argc, char *argv[])
{
	Harl Harl;

	if (argc == 2)
		Harl.complain(argv[1]);
	else
		std::cout << "PLS I DONT FUNCTION UNLES U PASS ME 1 ARGUMENT" << std::endl;

    return (1);
}
