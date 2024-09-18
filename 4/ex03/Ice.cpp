#include "Ice.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Ice::Ice() {
	type = "ice";	
	std::cout << "Ice default constructor called, type set to " << type << std::endl;
}

Ice::Ice(const Ice &model) {
	type = model.type;
	std::cout << "Ice model constructor called, type set to " << type << std::endl;

}

Ice &Ice::operator=(const Ice &model) {
	type = model.type;
	std::cout << "Ice =constructor called, type set to " << type << std::endl;
	return (*this);
}

Ice::Ice(std::string const &new_type) {
	type = new_type;	
	std::cout << "Ice default constructor called, type set to " << type << std::endl;
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Ice::~Ice() {
	std::cout << "Ice default destrucotr called" << std::endl;
}

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::string const &Ice::getType() const{
	return(type);
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}