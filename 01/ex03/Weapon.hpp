#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string newType);
		const std::string& getType();
		void setType(std::string newType);
	private:
		std::string type;
};

#endif