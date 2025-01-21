#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	AForm
{
private:

	const std::string	_name;
	bool 				_signed;
	const int			_grade_sig;
	const int			_grade_exe;	
	std::string			_target;

	

public:

/*--------------------CONSTRUCTORS-------------------*/
	AForm();
	AForm(std::string name, int grade_sig, int grade_exe, std::string target);
	AForm(const AForm &model);
	AForm &operator=(const AForm &model);

/*--------------------DESTRUCTORS--------------------*/

	virtual ~AForm() = 0;

/*-----------------------CLASES----------------------*/

	class				GradeTooHighException: public std::exception {
		public:
			const char *what() const throw();
	};
	class				GradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};
	class				FormNotSignedException: public std::exception {
		public:
			const char *what() const throw();
	};
/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string 	getName() const;
	std::string 	getTarget() const;
	int 			getGradeSig() const;
	int 			getGradeExe() const;
	bool			getSigned() const;
	void 			beSigned(const class Bureaucrat &bureaucrat);
	void			execute(Bureaucrat const & executor) const;
	virtual void	beExecuted() const = 0;

};

	std::ostream &operator<<(std::ostream &ostream, const AForm&model);

#endif
