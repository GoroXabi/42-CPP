#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap Juan("Juan");

	std::cout << "Stats:\n" << "[AD] " << Juan.get_AD() << "\n[EP] " << Juan.get_EP() << "\n[HP] " << Juan.get_HP() << std::endl;

	Juan.attack("Jose");
	Juan.takeDamage(1);
	Juan.beRepaired(5);
	Juan.takeDamage(9);
}
