#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

private:

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	void highFivesGuys(void);
	void attack(const std::string &target);
};

#endif