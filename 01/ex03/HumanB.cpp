#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
	: name(newName)
{

}

void HumanB::attack()
{
	if (!weapon)
	{
		std::cout << "No weapon!\n";
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}