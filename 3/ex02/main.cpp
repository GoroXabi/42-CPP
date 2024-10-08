#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "FragTrap.hpp"


int main()
{
	FragTrap Jon("Jon");

	std::cout << "Stats:\n" << "[AD] " << Jon.get_AD() << "\n[EP] " << Jon.get_EP() << "\n[HP] " << Jon.get_HP() << std::endl;

	Jon.attack("Jose");
	Jon.takeDamage(1);
	Jon.beRepaired(5);
	Jon.takeDamage(4);
	Jon.highFivesGuys();
	Jon.set_AD(0);
	Jon.takeDamage(0);
	Jon.attack("Jose");
	Jon.takeDamage(100);
	Jon.attack("Jose");
}
