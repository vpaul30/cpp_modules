#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
public:

	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack()
	{
		// std::cout << "MutantStack default constructor called.\n";
	}
	MutantStack(const std::stack<T> &other) : std::stack<T>(other)
	{
		// std::cout << "MutantStack copy constructor called.\n";
		// *this = other;
	}
	~MutantStack()
	{
		// std::cout << "MutantStack destructor called.\n";
	}
	MutantStack &operator=(const MutantStack &other)
	{
		// std::cout << "MutantStack assignment operator called.\n";
		this->c = other.c;
		return *this;
	}

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	T &operator[](unsigned int offset)
	{
		return *(this->c.begin() + offset);
	}
};

#endif