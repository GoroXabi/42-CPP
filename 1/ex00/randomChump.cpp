#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie brainroot;

	brainroot.set_name(name);

	brainroot.announce();
}