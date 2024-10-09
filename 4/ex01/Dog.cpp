#include "Dog.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Dog::Dog() {
	brain = new Brain();
	type = "Dog";
	std::cout << "Dog default constructor called, type set to " << type << std::endl;
}

Dog::Dog(const Dog &model): Animal(model) {
	brain = new Brain(*model.brain);
	std::cout << "Animal model constructor called, type set to " << type << std::endl;
}

Dog &Dog::operator=(const Dog &model) {
	Animal::operator=(model);
	brain = new Brain(*model.brain);
	std::cout << "Animal =constructor called, type set to " << type << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Dog::makeSound() const {
	std::cout << "wof Wof WOf WOF" << std::endl;
}
