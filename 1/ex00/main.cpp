#include <iostream>
#include "Zombie.hpp"


int main() {

	Zombie *Jaime = newZombie("Jaime");
	randomChump("Luis");
	Jaime->announce();
	delete Jaime;
    return (0);
}
