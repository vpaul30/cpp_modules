#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
	{
		std::cout << "===Vector===\n";
		std::vector<int> arr = {1, 2, 3, 4, 5};
		int value;
		std::vector<int>::iterator res;
		value = 3;
		res = easyfind(arr, value);
		if (res == arr.end())
			std::cout << value << " was not found!\n";
		else
			std::cout << value << " was found!\n";

		value = 0;
		res = easyfind(arr, value);
		if (res == arr.end())
			std::cout << value << " was not found!\n";
		else
			std::cout << value << " was found!\n";
	}

	{
		std::cout << "\n===Deque===\n";
		std::deque<int> deq = {1, 2, 3, 4, 5};
		int value = 3;
		std::deque<int>::iterator res;
		res = easyfind(deq, value);
		if (res == deq.end())
			std::cout << value << " was not found!\n";
		else
			std::cout << value << " was found!\n";

		value = 0;
		res = easyfind(deq, value);
		if (res == deq.end())
			std::cout << value << " was not found!\n";
		else
			std::cout << value << " was found!\n";
	}
	
}
