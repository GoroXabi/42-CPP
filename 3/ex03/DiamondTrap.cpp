#include "DiamondTrap.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

DiamondTrap::DiamondTrap() {
	name = "nameless";
	set_name(name + "_clap_name");
	set_type("DiamondTrap");
	set_HP(FragTrap::get_HP());
	set_EP(ScavTrap::get_EP());
	set_AD(FragTrap::get_AD());

	std::cout << "DiamondTrap default constructor called, name set to "<< name << " and " << get_name() << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name) {
	name = new_name;
	set_name(name + "_clap_name");
	set_type("DiamondTrap");
	set_HP(FragTrap::get_HP());
	set_EP(ScavTrap::get_EP());
	set_AD(FragTrap::get_AD());
	
	std::cout << "DiamondTrap constructor(string) called, name set to "<< name << " and " << get_name() << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &model): ClapTrap(model), ScavTrap(model), FragTrap(model), name(model.name) {
	std::cout << "DiamondTrap copy constructor called, name set to "<< name << " and " << get_name() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &model) {
	name = model.name;
	set_name(model.get_name());
	set_type(model.get_type());
	set_HP(model.get_HP());
	set_EP(model.get_EP());
	set_AD(model.get_AD());

	std::cout << "DiamondTrap =constructor called, name set to "<< name << " and " << get_name() << std::endl;

	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

DiamondTrap::~DiamondTrap() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void DiamondTrap::whoAmI() {
	std::cout << name << " IS HAVING A PERSONALITY DISORDER PROBLEM! " << get_name() << " may be his real name!" << std::endl;
}