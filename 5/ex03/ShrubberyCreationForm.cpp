#include "ShrubberyCreationForm.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm("ShrubberyCreationForm", 145, 137,"default") {


}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm", 145, 137,target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &model):
	AForm("ShrubberyCreationForm", 145, 137, model.getTarget()) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &model) {

	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	ShrubberyCreationForm::beExecuted() const {
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		std::cout << "File cannot be create" << std::endl;
	else
	{
		file << "		,d" << std::endl;
		file << "		88" << std::endl;
		file << "	  MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  " << std::endl;
		file << "		88    88P'   \"Y8 a8P_____88 a8P_____88" << std::endl;
		file << "		88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"" << std::endl;
		file << "		88,   88         \"8b,   ,aa \"8b,   ,aa  " << std::endl;
		file << "		\"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"' " << std::endl;
		file << std::endl;
		file << "		,d" << std::endl;
		file << "		88" << std::endl;
		file << "	  MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  " << std::endl;
		file << "		88    88P'   \"Y8 a8P_____88 a8P_____88" << std::endl;
		file << "		88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"" << std::endl;
		file << "		88,   88         \"8b,   ,aa \"8b,   ,aa  " << std::endl;
		file << "		\"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"' " << std::endl;
		file << std::endl;
		file << "		,d" << std::endl;
		file << "		88" << std::endl;
		file << "	  MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  " << std::endl;
		file << "		88    88P'   \"Y8 a8P_____88 a8P_____88" << std::endl;
		file << "		88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"" << std::endl;
		file << "		88,   88         \"8b,   ,aa \"8b,   ,aa  " << std::endl;
		file << "		\"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"' " << std::endl;	
	}
}