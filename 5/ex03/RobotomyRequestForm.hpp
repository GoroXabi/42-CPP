#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
private:

	std::string	_target;

public:

/*--------------------CONSTRUCTORS-------------------*/
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &model);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &model);

/*--------------------DESTRUCTORS--------------------*/

	~RobotomyRequestForm();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void beExecuted() const;
};

#endif
