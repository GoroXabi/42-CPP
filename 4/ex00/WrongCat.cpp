#include "WrongCat.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

WrongCat::WrongCat() {
	set_type("WrongCat");
	std::cout << "WrongCat default constructor called, type set to " << "WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &model): WrongAnimal(model) {
	std::cout << "WrongAnimal model constructor called, type set to " << get_type() << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &model) {
	WrongAnimal::operator=(model);
	std::cout << "WrongAnimal =constructor called, type set to " << get_type() << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	WrongCat::makeSound() const {
	std::cout << "I AM NOT A CAT SAVE ME PLS" << std::endl;
}
