#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &model);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &model);

/*--------------------DESTRUCTORS--------------------*/

	~ShrubberyCreationForm();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void	beExecuted() const;

};

#endif
