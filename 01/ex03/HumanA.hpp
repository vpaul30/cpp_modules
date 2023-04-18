#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string newName, Weapon& newWeapon);
		void attack();
	private:
		Weapon& weapon;
		std::string name;

};

#endif