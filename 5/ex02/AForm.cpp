#include "AForm.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

AForm::AForm():
	_name("default"),
	_signed(false),
	_grade_sig(75),
	_grade_exe(50),
	_target("default")
	{}

AForm::AForm(std::string name, int grade_sig, int grade_exe, std::string target):
	_name(name),
	_signed(false),
	_grade_sig(grade_sig),
	_grade_exe(grade_exe),
	_target(target){
	if (grade_exe < 1)
		throw GradeTooLowException();
	if (grade_exe > 150)
		throw GradeTooHighException();
	if (grade_sig < 1)
		throw GradeTooLowException();
	if (grade_sig > 150)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &model):
	_name(model._name),
	_signed(false),
	_grade_sig(model._grade_sig),
	_grade_exe(model._grade_exe),
	_target(model._target)
	{}


AForm &AForm::operator=(const AForm &model) {
	
	_signed = model._signed;
	_target = model._target;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

AForm::~AForm() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::string AForm::getName() const {
	return(_name);
}

std::string AForm::getTarget() const {
	return(_target);
}
	
int AForm::getGradeSig() const {
	return(_grade_sig);
}
	
int AForm::getGradeExe() const {
	return(_grade_exe);
}

bool	AForm::getSigned() const {
	return(_signed);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {

	if (_grade_sig < bureaucrat.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!_signed)
		throw FormNotSignedException();
	if (_grade_exe < executor.getGrade())
		throw GradeTooLowException();
	beExecuted();
}

/*--------------------------------------------------------------*/
/*							 CLASES								*/
/*--------------------------------------------------------------*/

const char	*AForm::GradeTooHighException::what() const throw() {
	return("Form grade Too High Exception");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return("Form grade Too Low Exception");
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return("Form Not Signed Exception");
}

/*--------------------------------------------------------------*/
/*						OTHER_FUNCTIONS							*/
/*--------------------------------------------------------------*/

std::ostream	&operator<<(std::ostream &ostream, const AForm &model) {

	ostream << "The form: " << model.getName() << ", needs a " << model.getGradeSig()
	 << " to be signed and a " << model.getGradeExe() << " to be exececuted" << std::endl;
	
	return(ostream);
}
