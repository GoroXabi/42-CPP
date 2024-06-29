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
	std::string	monster_type;
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
	std::string		get_type();
	int				get_HP();
	int				get_AD();
	int				get_EP();

	void			set_name(std::string new_name);
	void			set_type(std::string new_type);
	void			set_HP(int new_HP);
	void			set_AD(int new_AD);
	void			set_EP(int new_EP);

};

#endif
