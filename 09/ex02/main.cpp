#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "No arguments passed.\n";
		return 0;
	}

	std::vector<int> _vector;
	std::deque<int> _deque;
	int number;

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
			if (!std::isdigit(argv[i][j]))
			{
				std::cout << "Wrong input.\n";
				return 0;
			}
		number = atoi(argv[i]);
		_vector.push_back(number);
		_deque.push_back(number);
	}

	// std::cout << "\n===Vector===\n";
	// for (unsigned int i = 0; i < _vector.size(); i++)
	// 	std::cout << _vector[i] << std::endl;

	// std::cout << "\n===Deque===\n";
	// for (unsigned int i = 0; i < _deque.size(); i++)
	// 	std::cout << _deque[i] << std::endl;

	PmergeMe me(_vector, _deque);
	me.run();

	return 0;
}