#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{

	Intern					jose;
	AForm*					rrf;
	std::string 			target("prueba");
	Bureaucrat				paco("paco", 10);
	Bureaucrat				sebas("sebas", 1);
	ShrubberyCreationForm	a12(target);
	//RobotomyRequestForm		a22(target);
	PresidentialPardonForm	a32(target);
	std::string				reason;

	std::cout << HBLU << paco << RST << std::endl;
	std::cout << HMAG << a32 << RST << std::endl;

	rrf = jose.makeForm("robotomy request", "prueba");

	paco.signForm(a12);
	paco.signForm(*rrf);
	paco.signForm(a32);
	sebas.executeForm(a12);
	sebas.executeForm(*rrf);
	sebas.executeForm(a32);

	return (0);
};
