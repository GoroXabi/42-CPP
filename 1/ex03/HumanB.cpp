#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string new_name){
	name = new_name;
}


void	HumanB::attack(){
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(class Weapon &new_weapon){
	weapon = &new_weapon;
}