#include "Cat.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Cat::Cat() {
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat default constructor called, type set to " << type << std::endl;
}

Cat::Cat(const Cat &model): Animal(model) {
	brain = new Brain(*model.brain);
	std::cout << "Animal model constructor called, type set to " << type << std::endl;
}

Cat &Cat::operator=(const Cat &model) {
	Animal::operator=(model);
	brain = new Brain(*model.brain);
	std::cout << "Animal =constructor called, type set to " << type << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
