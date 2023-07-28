#include <iostream>
#include <string>
#include "iter.hpp"


struct Data
{
	int number;
	std::string str;

	Data() : number(0), str("") {}
	Data(int num, std::string s) : number(num), str(s) {}
};

void increaseBy3(int &num)
{
	num += 3;
}

void uppercase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

void modifyData(Data &item)
{
	increaseBy3(item.number);
	uppercase(item.str);
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
	std::string str_array[4] = {"hey", "my", "name", "is"};
	
	std::cout << "str_array:\n";
	for (int i = 0; i < 4; i++)
		std::cout << str_array[i] << std::endl;

	iter(str_array, 4, uppercase);

	std::cout << "str_array:\n";
	for (int i = 0; i < 4; i++)
		std::cout << str_array[i] << std::endl;

	std::cout << "\n===Data===\n";
	Data data_array[3];
	data_array[0] = Data(1, "one");
	data_array[1] = Data(2, "two");
	data_array[2] = Data(3, "three");

	std::cout << "data_array:\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "number: " << data_array[i].number;
		std::cout << " str: " << data_array[i].str << std::endl;
	}

	iter(data_array, 3, modifyData);

	std::cout << "data_array:\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "number: " << data_array[i].number;
		std::cout << " str: " << data_array[i].str << std::endl;
	}
}