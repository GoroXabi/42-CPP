#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &model);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &model);

/*--------------------DESTRUCTORS--------------------*/

	~PresidentialPardonForm();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void beExecuted() const;

};

#endif
