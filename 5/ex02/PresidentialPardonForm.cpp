#include "PresidentialPardonForm.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("PresidentialPardonForm", 25, 5, "default") {


}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &model):
	AForm("PresidentialPardonForm", 25, 5, model.getTarget()) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &model) {

	(void)model;
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
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}