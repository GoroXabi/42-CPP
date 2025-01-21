#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	Intern();
	Intern(const Intern &model);
	Intern &operator=(const Intern &model);

/*--------------------DESTRUCTORS--------------------*/

	~Intern();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	AForm *makeForm(std::string type, std::string target);

};

#endif
