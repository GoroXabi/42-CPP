#include "Cure.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Cure::Cure() {
	type = "cure";	
	std::cout << "Cure default constructor called, type set to " << type << std::endl;
}

Cure::Cure(const Cure &model): AMateria::AMateria(){
	type = model.type;
	std::cout << "Cure model constructor called, type set to " << type << std::endl;

}

Cure &Cure::operator=(const Cure &model) {
	type = model.type;
	std::cout << "Cure =constructor called, type set to " << type << std::endl;
	return (*this);
}

Cure::Cure(std::string const &new_type) {
	type = new_type;	
	std::cout << "Cure default constructor called, type set to " << type << std::endl;
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Cure::~Cure() {
	std::cout << "Cure default destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::string const &Cure::getType() const{
	return(type);
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure	*Cure::clone() const {
	return(new Cure(*this));
}

