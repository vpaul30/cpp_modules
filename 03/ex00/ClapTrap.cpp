#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
 : _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called without name.\n";
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called with name.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called.\n";
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " is destructed.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
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

	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!\n";
	if (amount > _hitPoints)
		amount = _hitPoints;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
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

	if (amount > 10)
	{
		std::cout << "Can't heal more than 10 hit points at once!\n";
		return;
	}
	std::cout << "ClapTrap " << _name << " is repairing for ";
	std::cout << amount << " points.\n";
	_hitPoints += amount;
	if (_hitPoints > 10)
		_hitPoints = 10;
	_energyPoints--;
}

void ClapTrap::printInfo()
{
	std::cout << "===INFO===\n";
	std::cout << _name << ":" << std::endl;
	std::cout << "HP: " << _hitPoints << std::endl;
	std::cout << "Energy: " << _energyPoints << std::endl;
	std::cout << "==========\n";
}