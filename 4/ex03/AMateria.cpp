#include "AMateria.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

AMateria::AMateria() {
	type = "materia";	
	std::cout << "Materia default constructor called, type set to " << type << std::endl;
}

AMateria::AMateria(const AMateria &model) {
	type = model.type;
	std::cout << "Materia model constructor called, type set to " << type << std::endl;

}

AMateria &AMateria::operator=(const AMateria &model) {
	type = model.type;
	std::cout << "Materia =constructor called, type set to " << type << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const &new_type) {
	type = new_type;	
	std::cout << "Materia default constructor called, type set to " << type << std::endl;
}

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::string const &AMateria::getType() const{
	return(type);
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	AMateria::use(ICharacter& target) {
	use(target);
}
