#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class	DiamondTrap: public ScavTrap, public FragTrap
{
	
private:
	std::string	name;

public:

/*--------------------CONSTRUCTORS-------------------*/
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &model);
	DiamondTrap &operator=(const DiamondTrap &model);

/*--------------------DESTRUCTORS--------------------*/

	~DiamondTrap();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void whoAmI();

};

#endif
