#include "PmergeMe.hpp"
#include <unistd.h>

PmergeMe::PmergeMe()
{
	// std::cout << "Default constructor called.\n";
}

PmergeMe::~PmergeMe()
{
	// std::cout << "Destructor called.\n";
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	// std::cout << "Copy constructor called.\n";
	*this = other;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	// std::cout << "Assignment operator called.\n";
	if (this == &other)
		return *this;
	_vector = other._vector;
	_vector_pend = other._vector_pend;
	_vector_time = other._vector_time;
	_deque = other._deque;
	_deque_pend = other._deque_pend;
	_deque_time = other._deque_time;
	return *this;
}

void PmergeMe::displayResult(int argc, char **argv)
{
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << "std::vector : " << _vector_time << " ms\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << "std::deque : " << _deque_time << " ms\n";
}

void PmergeMe::nextJacobNumber(int &prev, int &prev_prev)
{
	int tmp = prev;
	prev = prev + prev_prev * 2;
	prev_prev = tmp;
}

// ===== VECTOR =====
bool PmergeMe::sortVector(int argc, char **argv)
{
	clock_t start = clock();

	if (!initVector(argc, argv))
		return false;
	if (_vector.size() == 1)
	{
		clock_t end = clock();
		_vector_time = 1000.0 * (end-start) / CLOCKS_PER_SEC;
		return true;
	}
	int tmp_last = -1;
	if (_vector.size() % 2)
	{
		tmp_last = _vector.back();
		_vector.pop_back();
	}
	for (unsigned int i = 0; i < _vector.size(); i+=2)
	{
		if (_vector[i] < _vector[i + 1])
		{
			int tmp = _vector[i];
			_vector[i] = _vector[i + 1];
			_vector[i + 1] = tmp;
		}
	}

	mergeSortVector(0, _vector.size() - 1);

	bool erase_elem = true;
	for (unsigned int i = 0; i < _vector.size(); i++)
	{
		if (i % 2 == erase_elem)
		{
			_vector_pend.push_back(_vector[i]);
			_vector.erase(_vector.begin() + i);
			erase_elem = !erase_elem;
		}
	}
	int vector_size = _vector.size();

	_vector.insert(_vector.begin(), _vector_pend[0]);
	_vector_pend[0] = -1;
	_vector_pend.insert(_vector_pend.begin(), -1);

	// insertion order generator
	int jacob_number = 1;
	int jacob_prev_number = 1;

	int insert_count = 1;

	while (true)
	{
		nextJacobNumber(jacob_number, jacob_prev_number);
		if (jacob_number > vector_size)
			break;
		int insert_i = jacob_number - 1 + insert_count; // insertion index of next jacobstahl number
		std::vector<int>::iterator it = std::upper_bound(_vector.begin(), _vector.begin() + insert_i, _vector_pend[insert_i]);
		int pend_i = it - _vector.begin(); // index corresponding to index in main where just inserted number
		_vector.insert(it, _vector_pend[insert_i]);
		_vector_pend[insert_i] = -1;
		_vector_pend.insert(_vector_pend.begin() + pend_i, -1);
		insert_count++;
		// go backwards in pend and insert all numbers that are not -1
		while (insert_i >= 0)
		{
			if (_vector_pend[insert_i] == -1)
			{
				insert_i--;
				continue;
			}
			it = std::upper_bound(_vector.begin(), _vector.begin() + insert_i, _vector_pend[insert_i]);
			pend_i = it - _vector.begin();
			_vector.insert(it, _vector_pend[insert_i]);
			_vector_pend[insert_i] = -1;
			_vector_pend.insert(_vector_pend.begin() + pend_i, -1);
			insert_count++;
		}
	}
	// check last element of pend, if its not -1 then there are some numbers still left,
	// insert them starting from last
	int insert_i = _vector_pend.end() - 1 - _vector_pend.begin();
	while (insert_i >= 0)
	{
		if (_vector_pend[insert_i] == -1)
		{
			insert_i--;
			continue;
		}
		std::vector<int>::iterator it = std::upper_bound(_vector.begin(), _vector.begin() + insert_i, _vector_pend[insert_i]);
		int pend_i = it - _vector.begin();
		_vector.insert(it, _vector_pend[insert_i]);
		_vector_pend[insert_i] = -1;
		_vector_pend.insert(_vector_pend.begin() + pend_i, -1);
		insert_count++;
	}
	// if amount of elements was odd, need to add last element (that was unpaired)
	if (tmp_last != -1)
	{
		std::vector<int>::iterator it = std::upper_bound(_vector.begin(), _vector.end(), tmp_last);
		int pend_i = it - _vector.begin();
		_vector.insert(it, tmp_last);
		_vector_pend.insert(_vector_pend.begin() + pend_i, -1);
		insert_count++;
	}

	clock_t end = clock();
	_vector_time = 1000.0 * (end-start) / CLOCKS_PER_SEC;
	return true;
}

void PmergeMe::mergeSortVector(unsigned int begin, unsigned int end)
{
	if (begin + 1 >= end)
		return;
	
	unsigned int mid = begin + (end - begin) / 2;
	if (mid % 2 == 0)
		mid++;
	mergeSortVector(begin, mid);
	mergeSortVector(mid + 1, end);
	mergeVector(begin, mid, end);
}

void PmergeMe::mergeVector(unsigned int begin, unsigned int mid, unsigned int end)
{
	unsigned int left_size = mid - begin + 1;
	unsigned int right_size = end - mid;

	int* left = new int[left_size];
	int* right = new int[right_size];

	for (unsigned int i = 0; i < left_size; ++i)
		left[i] = _vector[begin + i];
	for (unsigned int i = 0; i < right_size; ++i)
		right[i] = _vector[mid + 1 + i];

	unsigned int left_i = 0, right_i = 0;
	unsigned int merged_i = begin;

	while (left_i < left_size && right_i < right_size)
	{
		if (left[left_i] <= right[right_i])
		{
			_vector[merged_i++] = left[left_i++];
			_vector[merged_i++] = left[left_i++];
		}
		else
		{
			_vector[merged_i++] = right[right_i++];
			_vector[merged_i++] = right[right_i++];
		}
	}

	while (left_i < left_size)
		_vector[merged_i++] = left[left_i++];
	
	while (right_i < right_size)
		_vector[merged_i++] = right[right_i++];
	
	delete[] left;
	delete[] right;
}

bool PmergeMe::initVector(int argc, char **argv)
{
	_vector.reserve(argc - 1);
	_vector_pend.reserve(argc - 1);
	int number;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
			if (!std::isdigit(argv[i][j]))
			{
				std::cout << "Wrong input.\n";
				return false;
			}
		number = atoi(argv[i]);
		if (std::find(_vector.begin(), _vector.end(), number) == _vector.end())
			_vector.push_back(number);
		else
		{
			std::cout << "Duplicate number.\n";
			return false;
		}
	}
	return true;
}

const std::vector<int>& PmergeMe::getVector() const
{
	return _vector;
}


// ===== DEQUE =====
bool PmergeMe::sortDeque(int argc, char **argv)
{
	clock_t start = clock();

	if (!initDeque(argc, argv))
		return false;
	if (_deque.size() == 1)
	{
		clock_t end = clock();
		_deque_time = 1000.0 * (end-start) / CLOCKS_PER_SEC;
		return true;
	}
	int tmp_last = -1;
	if (_deque.size() % 2)
	{
		tmp_last = _deque.back();
		_deque.pop_back();
	}
	for (unsigned int i = 0; i < _deque.size(); i+=2)
	{
		if (_deque[i] < _deque[i + 1])
		{
			int tmp = _deque[i];
			_deque[i] = _deque[i + 1];
			_deque[i + 1] = tmp;
		}
	}

	mergeSortDeque(0, _deque.size() - 1);

	bool erase_elem = true;
	for (unsigned int i = 0; i < _deque.size(); i++)
	{
		if (i % 2 == erase_elem)
		{
			_deque_pend.push_back(_deque[i]);
			_deque.erase(_deque.begin() + i);
			erase_elem = !erase_elem;
		}
	}
	int vector_size = _deque.size();

	_deque.insert(_deque.begin(), _deque_pend[0]);
	_deque_pend[0] = -1;
	_deque_pend.insert(_deque_pend.begin(), -1);

	// insertion order generator
	int jacob_number = 1;
	int jacob_prev_number = 1;

	int insert_count = 1;

	while (true)
	{
		nextJacobNumber(jacob_number, jacob_prev_number);
		if (jacob_number > vector_size)
			break;
		int insert_i = jacob_number - 1 + insert_count; // insertion index of next jacobstahl number
		std::deque<int>::iterator it = std::upper_bound(_deque.begin(), _deque.begin() + insert_i, _deque_pend[insert_i]);
		int pend_i = it - _deque.begin(); // index corresponding to index in main where just inserted number
		_deque.insert(it, _deque_pend[insert_i]);
		_deque_pend[insert_i] = -1;
		_deque_pend.insert(_deque_pend.begin() + pend_i, -1);
		insert_count++;
		// go backwards in pend and insert all numbers that are not -1
		while (insert_i >= 0)
		{
			if (_deque_pend[insert_i] == -1)
			{
				insert_i--;
				continue;
			}
			it = std::upper_bound(_deque.begin(), _deque.begin() + insert_i, _deque_pend[insert_i]);
			pend_i = it - _deque.begin();
			_deque.insert(it, _deque_pend[insert_i]);
			_deque_pend[insert_i] = -1;
			_deque_pend.insert(_deque_pend.begin() + pend_i, -1);
			insert_count++;
		}
	}
	// check last element of pend, if its not -1 then there are some numbers still left,
	// insert them starting from last
	int insert_i = _deque_pend.end() - 1 - _deque_pend.begin();
	while (insert_i >= 0)
	{
		if (_deque_pend[insert_i] == -1)
		{
			insert_i--;
			continue;
		}
		std::deque<int>::iterator it = std::upper_bound(_deque.begin(), _deque.begin() + insert_i, _deque_pend[insert_i]);
		int pend_i = it - _deque.begin();
		_deque.insert(it, _deque_pend[insert_i]);
		_deque_pend[insert_i] = -1;
		_deque_pend.insert(_deque_pend.begin() + pend_i, -1);
		insert_count++;
	}
	// if amount of elements was odd, need to add last element (that was unpaired)
	if (tmp_last != -1)
	{
		std::deque<int>::iterator it = std::upper_bound(_deque.begin(), _deque.end(), tmp_last);
		int pend_i = it - _deque.begin();
		_deque.insert(it, tmp_last);
		_deque_pend.insert(_deque_pend.begin() + pend_i, -1);
		insert_count++;
	}

	clock_t end = clock();
	_deque_time = 1000.0 * (end-start) / CLOCKS_PER_SEC;
	return true;
}

void PmergeMe::mergeSortDeque(unsigned int begin, unsigned int end)
{
	if (begin + 1 >= end)
		return;
	
	unsigned int mid = begin + (end - begin) / 2;
	if (mid % 2 == 0)
		mid++;
	mergeSortDeque(begin, mid);
	mergeSortDeque(mid + 1, end);
	mergeDeque(begin, mid, end);
}

void PmergeMe::mergeDeque(unsigned int begin, unsigned int mid, unsigned int end)
{
	unsigned int left_size = mid - begin + 1;
	unsigned int right_size = end - mid;

	int* left = new int[left_size];
	int* right = new int[right_size];

	for (unsigned int i = 0; i < left_size; ++i)
		left[i] = _deque[begin + i];
	for (unsigned int i = 0; i < right_size; ++i)
		right[i] = _deque[mid + 1 + i];

	unsigned int left_i = 0, right_i = 0;
	unsigned int merged_i = begin;

	while (left_i < left_size && right_i < right_size)
	{
		if (left[left_i] <= right[right_i])
		{
			_deque[merged_i++] = left[left_i++];
			_deque[merged_i++] = left[left_i++];
		}
		else
		{
			_deque[merged_i++] = right[right_i++];
			_deque[merged_i++] = right[right_i++];
		}
	}

	while (left_i < left_size)
		_deque[merged_i++] = left[left_i++];
	
	while (right_i < right_size)
		_deque[merged_i++] = right[right_i++];
	
	delete[] left;
	delete[] right;
}

bool PmergeMe::initDeque(int argc, char **argv)
{
	int number;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
			if (!std::isdigit(argv[i][j]))
			{
				std::cout << "Wrong input.\n";
				return false;
			}
		number = atoi(argv[i]);
		if (std::find(_deque.begin(), _deque.end(), number) == _deque.end())
			_deque.push_back(number);
		else
		{
			std::cout << "Duplicate number.\n";
			return false;
		}
	}
	return true;
}

const std::deque<int>& PmergeMe::getDeque() const
{
	return _deque;
}