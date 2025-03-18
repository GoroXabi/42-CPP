#include "Bureaucrat.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Bureaucrat::Bureaucrat(): _name("default") {

	_grade = 75;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {

	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
	_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat &model): _name(model._name) {

	_grade = model._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &model) {

	_grade = model._grade;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Bureaucrat::~Bureaucrat() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::string Bureaucrat::getName() const {
	return(_name);
}

int	Bureaucrat::getGrade() const {
	return(_grade);
}

void Bureaucrat::promote() {
	
	_grade--;
	if (_grade < 1)
		throw GradeTooLowException();
}

void Bureaucrat::demote() {

	_grade++;
	if (_grade > 150)
		throw GradeTooHighException();
}


void	Bureaucrat::signForm(Form &form) {

	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName();
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << "\033[91m " << e.what() << "\033[0m" << std::endl;
	}
	
}

/*--------------------------------------------------------------*/
/*							 CLASES								*/
/*--------------------------------------------------------------*/

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return("Grade Too High Exception");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return("Grade Too Low Exception");
}

/*--------------------------------------------------------------*/
/*						OTHER_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &model) {

	ostream << model.getName() << ", bureaucrat grade " << model.getGrade();
	
	return(ostream);
}
