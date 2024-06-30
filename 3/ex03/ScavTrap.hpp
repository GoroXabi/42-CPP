#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &model);
	ScavTrap &operator=(const ScavTrap &model);

/*--------------------DESTRUCTORS--------------------*/

	~ScavTrap();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	void guardGate();
};

#endif
