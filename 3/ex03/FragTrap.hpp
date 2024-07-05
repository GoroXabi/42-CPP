#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &model);
	FragTrap &operator=(const FragTrap &model);

/*--------------------DESTRUCTORS--------------------*/

	~FragTrap();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	void highFivesGuys(void);
};

#endif
