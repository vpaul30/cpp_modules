#include <iostream>
#include "ClapTrap.hpp"

int main( void )
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
	return 0;
}