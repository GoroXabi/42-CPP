#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *brainroot = new Zombie;

	brainroot->set_name(name);
	
	return (brainroot);
}
