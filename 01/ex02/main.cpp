#include <iostream>
#include <iomanip>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << std::left;
	std::cout << std::setw(40) << "Memory address of the string: ";
	std::cout << &string << std::endl;
	std::cout << std::setw(40) << "Memory address held by stringPTR: ";
	std::cout << stringPTR << std::endl;
	std::cout << std::setw(40) << "Memory address held by stringREF: ";
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(40) << "Value of the string: ";
	std::cout << string << std::endl;
	std::cout << std::setw(40) << "Value pointed to by stringPTR: ";
	std::cout << *stringPTR << std::endl;
	std::cout << std::setw(40) << "Value pointed to by stringREF: ";
	std::cout << stringREF << std::endl;
}