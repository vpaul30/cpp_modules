#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
		scavTrap.beRepaired(10);
		scavTrap.printInfo();
		scavTrap.guardGate();
	}

	std::cout << "\n===FRAGTRAP TEST===\n\n";

	{
		FragTrap fragTrap("Mark");
		fragTrap.printInfo();
		fragTrap.attack("someone");
		fragTrap.takeDamage(50);
		fragTrap.printInfo();
		fragTrap.beRepaired(5);
		fragTrap.printInfo();
		fragTrap.highFivesGuys();
	}

	return 0;
}