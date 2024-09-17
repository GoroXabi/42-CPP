#include "AAnimal.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

AAnimal::AAnimal() {
	type = "animal";
	std::cout << "Animal default constructor called, type set to " << "animal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &model) {
	type = model.type;
	std::cout << "Animal copy constructor called, type set to " << model.type << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &model) {
	type = model.type;
	std::cout << "Animal =constructor called, type set to " << model.type << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/


std::string	AAnimal::get_type() const {
	return(type);
}

/*--------------------------------------------------------------*/
/*							SET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	AAnimal::set_type(std::string new_type){
	type = new_type;
}