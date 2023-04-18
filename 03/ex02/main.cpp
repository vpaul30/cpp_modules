#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap fragTrap("John");
	fragTrap.printInfo();
	fragTrap.attack("someone");
	fragTrap.printInfo();
	fragTrap.highFivesGuys();

	FragTrap test = FragTrap("Mark");
	test.printInfo();

	return 0;
}