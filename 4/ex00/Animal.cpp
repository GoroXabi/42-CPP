#include "Animal.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Animal::Animal() {
	type = "animal";
	std::cout << "Animal default constructor called, type set to " << "animal" << std::endl;
}

Animal::Animal(const Animal &model) {
	type = model.type;
	std::cout << "Animal copy constructor called, type set to " << model.type << std::endl;
}

Animal &Animal::operator=(const Animal &model) {
	type = model.type;
	std::cout << "Animal =constructor called, type set to " << model.type << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Animal::makeSound() const {
	std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
}

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/


std::string	Animal::get_type() const {
	return(type);
}

/*--------------------------------------------------------------*/
/*							SET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Animal::set_type(std::string new_type){
	type = new_type;
}