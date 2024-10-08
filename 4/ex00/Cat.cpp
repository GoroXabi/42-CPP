#include "Cat.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat default constructor called, type set to " << "Cat" << std::endl;
}

Cat::Cat(const Cat &model): Animal(model) {
	std::cout << "Animal model constructor called, type set to " << type << std::endl;
}

Cat &Cat::operator=(const Cat &model) {
	Animal::operator=(model);
	std::cout << "Animal =constructor called, type set to " << type << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
