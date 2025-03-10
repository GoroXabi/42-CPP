#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Form
{
private:

	const std::string	_name;
	bool 				_signed;
	const int			_grade_sig;
	const int			_grade_exe;

public:

/*--------------------CONSTRUCTORS-------------------*/
	Form();
	Form(std::string name, int grade_sig, int grade_exe);
	Form(const Form &model);
	Form &operator=(const Form &model);

/*--------------------DESTRUCTORS--------------------*/

	~Form();

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
	int 		getGradeSig() const;
	int 		getGradeExe() const;
	bool		getSigned() const;
	void 		beSigned(const class Bureaucrat &bureaucrat);

};

	std::ostream &operator<<(std::ostream &ostream, const Form&model);

#endif
