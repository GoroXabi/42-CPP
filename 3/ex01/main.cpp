#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "ScavTrap.hpp"


int main()
{
	ScavTrap Julio("Julio");

	std::cout << "Stats:\n" << "[AD] " << Julio.get_AD() << "\n[EP] " << Julio.get_EP() << "\n[HP] " << Julio.get_HP() << std::endl;

	Julio.attack("Jose");
	Julio.takeDamage(1);
	Julio.beRepaired(5);
	Julio.takeDamage(4);
	Julio.guardGate();
	Julio.takeDamage(0);
	Julio.attack("Jose");
	Julio.takeDamage(100);
	Julio.attack("Jose");
}
