#include "Dog.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Dog::Dog() {
	set_type("Dog");
	std::cout << "Dog default constructor called, type set to " << "Dog" << std::endl;
}

Dog::Dog(const Dog &model): Animal(model) {
	std::cout << "Animal model constructor called, type set to " << get_type() << std::endl;
}

Dog &Dog::operator=(const Dog &model) {
	Animal::operator=(model);
	std::cout << "Animal =constructor called, type set to " << get_type() << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Dog::makeSound() const {
	std::cout << "wof Wof WOf WOF" << std::endl;
}