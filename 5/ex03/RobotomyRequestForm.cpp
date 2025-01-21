#include "RobotomyRequestForm.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("RobotomyRequestForm", 72, 45, "default") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &model):
	AForm("RobotomyRequestForm", 72, 45,model.getTarget()) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &model) {

	(void)model;
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
		std::cout << getTarget() << " has been robotomized!" << std::endl;
	else
		 std::cout << getTarget() << " robotomi failed :(" << std::endl;
}