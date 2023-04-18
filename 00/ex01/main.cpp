#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phoneBook;

	std::cout << "Enter the command (ADD, SEARCH or EXIT):" << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			phoneBook.add_contact();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (input == "EXIT")
			exit(0);
	}
	return 0;
}