#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanA(std::string new_name, class Weapon &new_weapon);
	void	attack();
};
#endif
