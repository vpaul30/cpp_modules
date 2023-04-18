#include <iostream>
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "Debug message.\n";	
}

void Harl::info(void)
{
	std::cout << "Info message.\n";
}

void Harl::warning(void)
{
	std::cout << "Warning message.\n";
}

void Harl::error(void)
{
	std::cout << "Error message.\n";
}

void Harl::complain(std::string level)
{
	std::string funcNames[4] = {"debug", "info", "warning", "error"};
	void (Harl::*funcPtrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};


	for (int i = 0; i < 4; i++)
	{
		if (funcNames[i] == level)
			(this->*funcPtrs[i])();

	}
}