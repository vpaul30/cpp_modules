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

	PmergeMe me;
	if (me.sortVector(argc, argv) == false)
		return 0;
	if (me.sortDeque(argc, argv) == false)
		return 0;

	me.displayResult(argc, argv);

	// std::cout << "==============================\n";
	// std::cout << "=== CHECK_SORT===\n";
	// std::vector<int> me_vector = me.getVector();
	// std::deque<int> me_deque = me.getDeque();

	// // for (int i = 0; i < me_vector.size(); i++)
	// // 	std::cout << me_vector[i] << " ";
	// // std::cout << std::endl;

	// std::vector<int> check_sort_vector;
	// for (int i = 1; i < argc; i++)
	// {
	// 	int number = atoi(argv[i]);
	// 	check_sort_vector.push_back(number);
	// }
	// std::sort(check_sort_vector.begin(), check_sort_vector.end());

	// std::deque<int> check_sort_deque;
	// for (int i = 1; i < argc; i++)
	// {
	// 	int number = atoi(argv[i]);
	// 	check_sort_deque.push_back(number);
	// }
	// std::sort(check_sort_deque.begin(), check_sort_deque.end());

	// // for (int i = 0; i < check_sort.size(); i++)
	// // 	std::cout << check_sort[i] << " ";
	// // std::cout << std::endl;
	// if (me_vector == check_sort_vector)
	// 	std::cout << "VECTOR SUCCESS!\n";
	// else
	// 	std::cout << "VECTOR FAILURE!\n";

	// if (me_deque == check_sort_deque)
	// 	std::cout << "DEQUE SUCCESS!\n";
	// else
	// 	std::cout << "DEQUE FAILURE!\n";

	return 0;
}