#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int number);

	void addRandomNumbers(int amount);

	unsigned int shortestSpan();

	unsigned int longestSpan();

	void displayNumbers();

	template<typename T>
	void addManyNumbers(T begin, T end)
	{
		for (T it = begin; it != end; it++)
			addNumber(*it);
	}

private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

	class NoSpaceException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotEnoughNumbers : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
};

#endif