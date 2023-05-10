#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	std::cout << "===CLAPTRAP TEST===\n\n";

	{
		ClapTrap clapTrap("Billy");
		clapTrap.attack("Bob");
		clapTrap.takeDamage(7);
		clapTrap.printInfo();
		clapTrap.beRepaired(5);
		clapTrap.printInfo();

		for (int i = 0; i < 10; i++)
			clapTrap.attack("someone");
		std::cout << "==========\n";
	}

	std::cout << "\n===SCAVTRAP TEST===\n\n";

	{
		ScavTrap scavTrap("John");
		scavTrap.printInfo();
		scavTrap.attack("someone");
		scavTrap.printInfo();
		scavTrap.takeDamage(25);
		scavTrap.beRepaired(20);
		scavTrap.printInfo();
		scavTrap.guardGate();
	}

	std::cout << "\n===ANOTHER TEST===\n\n";

	ClapTrap *ptr = new ScavTrap("Mike");
	ptr->attack("someone");
	delete ptr;

	return 0;
}