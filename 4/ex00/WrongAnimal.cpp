#include "WrongAnimal.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

WrongAnimal::WrongAnimal() {
	type = "animal";
	std::cout << "WrongAnimal default constructor called, type set to " << "Wrong_animal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &model) {
	type = model.type;
	std::cout << "WrongAnimal copy constructor called, type set to " << model.type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &model) {
	type = model.type;
	std::cout << "WrongAnimal =constructor called, type set to " << model.type << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	WrongAnimal::makeSound() const {
	std::cout << "I AM NOT AN ANIMAL SAVE ME PLS" << std::endl;
}

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/


std::string	WrongAnimal::get_type() const {
	return(type);
}

/*--------------------------------------------------------------*/
/*							SET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	WrongAnimal::set_type(std::string new_type){
	type = new_type;
}