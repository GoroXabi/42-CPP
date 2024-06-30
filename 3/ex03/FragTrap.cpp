#include "FragTrap.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

FragTrap::FragTrap() {
	set_name("nameless");
	set_type("FragTrap");
	set_HP(100);
	set_EP(100);
	set_AD(30);

	std::cout << "FragTrap default constructor called, name set to " << get_name() << std::endl;
}

FragTrap::FragTrap(std::string name) {
	set_name(name);
	set_type("FragTrap");
	set_HP(100);
	set_EP(100);
	set_AD(30);

	std::cout << "FragTrap constructor(string) called, name set to " << get_name() << std::endl;

}

FragTrap::FragTrap(const FragTrap &model): ClapTrap(model) {
	std::cout << "FragTrap copy constructor called, name set to " << get_name() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &model) {
	ClapTrap::operator=(model);
	std::cout << "FragTrap =constructor called, name set to " << get_name() << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

FragTrap::~FragTrap() {
	std::cout << "FragTrap desctructor for " << get_name() <<" called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << get_name() <<" gives you a high five making him friendly!" << std::endl;
}
