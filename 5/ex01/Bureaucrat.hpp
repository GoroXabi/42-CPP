#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:

/*--------------------CONSTRUCTORS-------------------*/

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &model);
	Bureaucrat &operator=(const Bureaucrat &model);

/*--------------------DESTRUCTORS--------------------*/

	~Bureaucrat();

/*-----------------------CLASES----------------------*/

	class				GradeTooHighException: public std::exception {
		public:
			const char *what() const throw();
	};
	class				GradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};

/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string getName() const;
	int			getGrade() const;
	void		promote();
	void		demote();
	void		signForm(class Form &form);

};

	std::ostream &operator<<(std::ostream &ostream, const Bureaucrat&model);

#endif
