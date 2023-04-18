#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	std::cout << "\nnewZombie()\n";
	Zombie* zombie2 = newZombie("Mark");
	zombie2->announce();
	delete zombie2;

	std::cout << "\nrandomChump()\n";
	randomChump("Mike");
}