#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde = new Zombie[N];
	int i;

	for (i = 0; i < N; i++) {
		Horde[i].set_name(name);
	}
	return (Horde);

}