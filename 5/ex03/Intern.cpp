#include "Intern.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Intern::Intern() {

}

Intern::Intern(const Intern &model) {

	(void)model;
}

Intern &Intern::operator=(const Intern &model) {
	
	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Intern::~Intern() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

AForm	*Intern::makeForm(std::string type, std::string target) {

	std::string form_types[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int 		i;
	for (i = 0; i < 3 && type != form_types[i]; i++)
	{
		;	
	}
	switch (i)
	{
		case 0:
		{
			AForm *new_form = new PresidentialPardonForm(target);
			std::cout << "Inter creates " << *new_form << std::endl;
			return (new_form);
		}
		case 1:
		{
			AForm *new_form = new RobotomyRequestForm(target);
			std::cout << "Inter creates " << *new_form << std::endl;
			return (new_form);
		}		
		case 2:
		{
			AForm *new_form = new ShrubberyCreationForm(target);
			std::cout << "Inter creates " << *new_form << std::endl;
			return (new_form);
		}		
		default:
			std::cout << "The type provided isnt expected" << std::endl; 
	}
	return(NULL);

}
