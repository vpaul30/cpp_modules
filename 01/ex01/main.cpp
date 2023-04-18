#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie *zombie_horde = zombieHorde(5, "John");

	zombie_horde[0].announce();
	zombie_horde[2].announce();
	zombie_horde[4].announce();

	delete[] zombie_horde;
}