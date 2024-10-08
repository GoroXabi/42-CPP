#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "DiamondTrap.hpp"


int main()
{

	DiamondTrap Josu("Josu");
	DiamondTrap Javi("Javi");
	Javi = Josu;

	std::cout << "Stats:\n" << "[AD] " << Javi.get_AD() << "\n[EP] " << Javi.get_EP() << "\n[HP] " << Javi.get_HP() << std::endl;

	Javi.attack("Jose");
	Javi.takeDamage(1);
	Javi.beRepaired(5);
	Javi.takeDamage(4);
	Javi.highFivesGuys();
	Javi.whoAmI();
	Javi.set_AD(0);
	Javi.takeDamage(0);
	Javi.attack("Jose");
	Javi.takeDamage(100);
	Javi.attack("Jose");

}
