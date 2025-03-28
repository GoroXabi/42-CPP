#include "Form.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Form::Form():
	_name("default"),
	_signed(false),
	_grade_sig(75),
	_grade_exe(50)
	{}

Form::Form(std::string name, int grade_sig, int grade_exe):
	_name(name),
	_signed(false),
	_grade_sig(grade_sig),
	_grade_exe(grade_exe){
	if (grade_exe < 1)
		throw GradeTooLowException();
	if (grade_exe > 150)
		throw GradeTooHighException();
	if (grade_sig < 1)
		throw GradeTooLowException();
	if (grade_sig > 150)
		throw GradeTooHighException();
}

Form::Form(const Form &model):
	_name(model._name),
	_signed(false),
	_grade_sig(model._grade_sig),
	_grade_exe(model._grade_exe)
	{}


Form &Form::operator=(const Form &model) {
	
	_signed = model._signed;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Form::~Form() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::string Form::getName() const {
	return(_name);
}
	
int Form::getGradeSig() const {
	return(_grade_sig);
}
	
int Form::getGradeExe() const {
	return(_grade_exe);
}

bool	Form::getSigned() const {
	return(_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {

	if (_grade_sig < bureaucrat.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

/*--------------------------------------------------------------*/
/*							 CLASES								*/
/*--------------------------------------------------------------*/

const char	*Form::GradeTooHighException::what() const throw() {
	return("Form grade Too High Exception");
}
const char	*Form::GradeTooLowException::what() const throw() {
	return("Form grade Too Low Exception");
}

/*--------------------------------------------------------------*/
/*						OTHER_FUNCTIONS							*/
/*--------------------------------------------------------------*/

std::ostream	&operator<<(std::ostream &ostream, const Form &model) {

	ostream << "The form: " << model.getName() << ", needs a " << model.getGradeSig()
	 << " to be signed and a " << model.getGradeExe() << " to be exececuted" << std::endl;
	
	return(ostream);
}
