#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructror called without name.\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructror called with name.\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructror called.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destructed.\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " is asking for a high five.\n";
}

void FragTrap::attack(const std::string &target)
{
	if (!_energyPoints)
		return;
	std::cout << "FragTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
}