#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{

public:
	PmergeMe();
	PmergeMe(std::vector<int> vec, std::deque<int> deq);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	void run();
	void sortVector();
	void sortDeque();
private:
	std::vector<int> _vector;
	std::deque<int> _deque;

};

#endif