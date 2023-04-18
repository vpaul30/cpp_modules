#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap scavTrap("John");
	scavTrap.printInfo();
	scavTrap.attack("someone");
	scavTrap.printInfo();

	ScavTrap test = ScavTrap("Mark");
	test.printInfo();

	return 0;
}