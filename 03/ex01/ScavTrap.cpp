#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructror called without name.\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructror called with name.\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructror called.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " is destructed.\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is protecting the gate.\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (!_energyPoints)
	{
		std::cout << "No energy!\n";
		return;
	}
	if (!_hitPoints)
	{
		std::cout << "No hit points!\n";
		return;
	}

	std::cout << "ScavTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
}