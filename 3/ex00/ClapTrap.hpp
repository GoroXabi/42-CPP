#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class	ClapTrap
{
private:

	std::string name;
	int			HP;
	int			EP;
	int			AD;

public:

/*--------------------CONSTRUCTORS-------------------*/

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &model);
	ClapTrap &operator=(const ClapTrap &model);

/*--------------------DESTRUCTORS--------------------*/

	~ClapTrap();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	showInfo();

	std::string		get_name();
	int				get_HP();
	int				get_AD();
	int				get_EP();

};

#endif
