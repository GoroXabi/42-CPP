#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{

	std::string 			target("prueba");
	Bureaucrat				paco("paco", 10);
	Bureaucrat				sebas("sebas", 1);
	ShrubberyCreationForm	a12(target);
	RobotomyRequestForm		a22(target);
	PresidentialPardonForm	a32(target);

	std::cout << HBLU << paco << RST << std::endl;
	std::cout << HMAG << a32 << RST << std::endl;

	try
	{
		sebas.executeForm(a12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	paco.signForm(a12);
	paco.signForm(a22);
	paco.signForm(a32);
	sebas.executeForm(a12);
	sebas.executeForm(a22);
	sebas.executeForm(a32);

	return (0);
};
