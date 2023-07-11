#include <iostream>
#include <string>
#include "iter.hpp"

void increaseBy3(int &num)
{
	num += 3;
}

void uppercase(std::string &str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main()
{
	// int
	std::cout << "===int===\n";
	int int_array[3] = {1, 2, 3};

	std::cout << "int_array:\n";
	for (int i = 0; i < 3; i++)
		std::cout << int_array[i] << std::endl;

	iter(int_array, 3, increaseBy3);

	std::cout << "int_array:\n";
	for (int i = 0; i < 3; i++)
		std::cout << int_array[i] << std::endl;

	std::cout << "\n===string===\n";
	std::string str_array[3] = {"hey", "my", "name"};
	
	std::cout << "str_array:\n";
	for (int i = 0; i < 3; i++)
		std::cout << str_array[i] << std::endl;

	iter(str_array, 3, uppercase);

	std::cout << "str_array:\n";
	for (int i = 0; i < 3; i++)
		std::cout << str_array[i] << std::endl;
}