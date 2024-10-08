#include "ScavTrap.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

ScavTrap::ScavTrap() {
	set_name("nameless");
	set_HP(100);
	set_EP(50);
	set_AD(20);

	std::cout << "ScavTrap default constructor called, name set to " << get_name() << std::endl;
}

ScavTrap::ScavTrap(std::string new_name) {
	set_name(new_name);
	set_HP(100);
	set_EP(50);
	set_AD(20);

	std::cout << "ScavTrap constructor(string) called, name set to " << get_name() << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &model): ClapTrap(model) {
	std::cout << "ScavTrap copy constructor called, name set to " << get_name() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &model) {
	ClapTrap::operator=(model);
	std::cout << "ScavTrap =constructor called, name set to " << get_name() << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap desctructor for " << get_name() <<" called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << get_name() <<" is in Gate Keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (get_EP() == 0) {
		std::cout << "ScavTrap " << get_name() << " has no energy left!" << std::endl;
		return ;
	}
	if (get_HP() == 0) {
		std::cout << "ScavTrap " << get_name() << " has no HP left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << get_name() << " atacks " << target << 
	", causing " << get_AD() << " points of damage!" << std::endl;
	set_EP(get_EP() - 1);
}
