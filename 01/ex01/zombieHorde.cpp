#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombie_horde = new Zombie[N];
	// check for allocation error
	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].set_name(name);
	}
	return zombie_horde;
}