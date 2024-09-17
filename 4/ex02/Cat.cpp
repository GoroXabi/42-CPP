#include "Cat.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Cat::Cat() {
	brain = new Brain();
	set_type("Cat");
	std::cout << "Cat default constructor called, type set to " << "Cat" << std::endl;
}

Cat::Cat(const Cat &model): AAnimal(model) {
	brain = new Brain(*model.brain);
	std::cout << "Animal model constructor called, type set to " << get_type() << std::endl;
}

Cat &Cat::operator=(const Cat &model) {
	AAnimal::operator=(model);
	brain = new Brain(*model.brain);
	std::cout << "Animal =constructor called, type set to " << get_type() << std::endl;
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
