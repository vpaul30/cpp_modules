#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << "Default constructor called.\n";
}

PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq) : _vector(vec), _deque(deq)
{
	// std::cout << "Constructor called.\n";
}

PmergeMe::~PmergeMe()
{
	// std::cout << "Destructor called.\n";
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	// std::cout << "Assignment operator called.\n";
	if (this == &other)
		return *this;
	_vector = other._vector;
	_deque = other._deque;
	return *this;
}

void PmergeMe::run()
{
	std::cout << "\n===Vector===\n";
	for (unsigned int i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << std::endl;

	std::cout << "\n===Deque===\n";
	for (unsigned int i = 0; i < _deque.size(); i++)
		std::cout << _deque[i] << std::endl;
}

void PmergeMe::sortVector()
{
	/*
		split vector into pairs (last element unpaired if odd amount)
		sort pairs by their highest number
	*/
}

void PmergeMe::sortDeque()
{
	
}