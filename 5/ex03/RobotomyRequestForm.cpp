#include "RobotomyRequestForm.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("RobotomyRequestForm", 72, 45), _target("default") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &model):
	AForm("RobotomyRequestForm", 72, 45), _target(model._target) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &model) {
	
	this->_target = model._target;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void RobotomyRequestForm::beExecuted() const {
	std::cout << "drilling..." << std::endl; sleep(1);
	std::cout << "drilling..." << std::endl; sleep(1);
	std::cout << "drilling..." << std::endl; sleep(1);
	std::cout << "drilling..." << std::endl; sleep(1);
	srand (time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		 std::cout << _target << " robotomi failed :(" << std::endl;
}