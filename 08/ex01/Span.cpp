#include "Span.hpp"
#include <cstdlib>
#include <ctime>

Span::Span() : _maxSize(0)
{
	// std::cout << "Span default constructor is called\n";
}

Span::Span(unsigned int n) : _maxSize(n)
{
	// std::cout << "Span constructor is called\n";
}

Span::Span(const Span &other)
{
	// std::cout << "Span copy constructor is called\n";
	*this = other;
}

Span::~Span()
{
	// std::cout << "Span destructor is called\n";
}

Span &Span::operator=(const Span &other)
{
	// std::cout << "Span assignment operator is called\n";
	_maxSize = other._maxSize;
	_numbers = other._numbers;
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() < _maxSize)
		_numbers.push_back(number);
	else
	 	throw NoSpaceException();
}

void Span::addRandomNumbers(int amount)
{
	srand(time(NULL));
	for (int i = 0; i < amount; i++)
		addNumber(rand() % 100);
}

long long Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbers();
	
	std::sort(_numbers.begin(), _numbers.end());
	long long shortest = (long long)_numbers[1] - (long long)_numbers[0];
	for (unsigned int i = 1; i < _numbers.size() - 1; i++)
	{
		if (shortest > _numbers[i + 1] - _numbers[i])
			shortest = (long long)_numbers[i + 1] - (long long)_numbers[i];
	}

	return shortest;
}

long long Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbers();

	std::sort(_numbers.begin(), _numbers.end());
	long long longest = (long long)_numbers.back() - (long long)_numbers.front();

	return longest;
}

void Span::displayNumbers()
{
	for (unsigned int i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << std::endl;
}

const char *Span::NoSpaceException::what() const throw()
{
	return "Error: no space for new number.";
}

const char *Span::NotEnoughNumbers::what() const throw()
{
	return "Error: there must be at least 2 numbers.";
}