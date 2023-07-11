#include "Character.hpp"

Character::Character() : _name("default")
{
	std::cout << "Character default constructor called.\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructor called.\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called.\n";
	*this = other;
}

Character::~Character()
{
	std::cout << "Character destructor called.\n";
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator called.\n";
	_name = other._name + "_copy";

	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();

	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
		{
			std::cout << "* " << m->getType() << " is already equipped in slot " << i << " *\n";
			return;
		}
		if (_inventory[i] == NULL)
		{
			std::cout << "* " << m->getType() << " equipped in slot " << i << " *\n";
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "* the inventory is full! *\n";
}

void Character::unequip(int idx)
{
	if (_inventory[idx] == NULL)
	{
		std::cout << "* nothing to unequip at slot " << idx << " *\n";
	}
	std::cout << "* " << _inventory[idx]->getType() << " at slot " << idx << " is unequipped *\n";
	materiasOnFloor[materiasOnFloorIdx] = _inventory[idx];
	materiasOnFloorIdx++;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx] == NULL)
	{
		std::cout << "* nothing to use at slot " << idx << " *\n";
	}
	_inventory[idx]->use(target);
}