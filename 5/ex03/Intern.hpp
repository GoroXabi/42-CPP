#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.cpp"

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

	makeForm(std::string name, std::string target);

};

#endif
