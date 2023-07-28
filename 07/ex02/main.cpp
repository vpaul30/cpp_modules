#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	std::cout << "===Empty===\n";
	try
	{
		Array<int> arr;
		std::cout << "Array size = " << arr.size() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << "Index is out of bounds.\n";
	}

	std::cout << "\n===Deep Copy===\n";
	try
	{
		Array<std::string> arr(3);
		arr[0] = "one";
		arr[1] = "two";
		arr[2] = "three";
		for (int i = 0; i < 3; i++)
			std::cout << "arr: " << arr[i] << std::endl;

		Array<std::string> arr_copy(arr);
		for (int i = 0; i < 3; i++)
			std::cout << "arr_copy: " << arr_copy[i] << std::endl;
		std::cout << "---\n";
		arr_copy[1] = "TWO";
		for (int i = 0; i < 3; i++)
			std::cout << "arr: " << arr[i] << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "arr_copy: " << arr_copy[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Index is out of bounds.\n";
	}

	std::cout << "\n===Exception===\n";
	try
	{
		Array<int> arr(10);
		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = i;
		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i] << std::endl;
		std::cout << "---\n";
		arr[10] = 10;
	} 
	catch (std::exception &e)
	{
		std::cerr << "Index is out of bounds.\n";
	}

}