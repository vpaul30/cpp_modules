#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string newName);
		void attack();
		void setWeapon(Weapon &newWeapon);
	private:
		Weapon* weapon = NULL;
		std::string name;

};

#endif