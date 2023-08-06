#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe
{

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	void nextJacobNumber(int &prev, int &prev_prev);
	// vector
	bool sortVector(int argc, char **argv);
	bool initVector(int argc, char **argv);
	void mergeSortVector(unsigned int begin, unsigned int end);
	void mergeVector(unsigned int begin, unsigned int mid, unsigned int end);
	const std::vector<int>& getVector() const;
	// deque
	bool sortDeque(int argc, char **argv);
	bool initDeque(int argc, char **argv);
	void mergeSortDeque(unsigned int begin, unsigned int end);
	void mergeDeque(unsigned int begin, unsigned int mid, unsigned int end);
	const std::deque<int>& getDeque() const;

	void displayResult(int argc, char **argv);
private:
	// vector
	std::vector<int> _vector;
	std::vector<int> _vector_pend;
	double _vector_time;
	// deque
	std::deque<int> _deque;
	std::deque<int> _deque_pend;
	double _deque_time;

};

#endif