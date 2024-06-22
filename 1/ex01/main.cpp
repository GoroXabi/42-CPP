#include <iostream>
#include "Zombie.hpp"


int main() {

	int N = 5;
	int i;
	Zombie *Horde = zombieHorde(N, "Legion");

	for (i = 0; i < N; i++) {
		Horde[i].announce();
	}
	delete[] Horde;
    return (0);
}
