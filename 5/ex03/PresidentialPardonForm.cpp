#include "PresidentialPardonForm.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("PresidentialPardonForm", 25, 5), _target("default") {


}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &model):
	AForm("PresidentialPardonForm", 25, 5), _target(model._target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &model) {
	
	this->_target = model._target;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void PresidentialPardonForm::beExecuted() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}