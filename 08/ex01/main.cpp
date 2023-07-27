#include "Span.hpp"
#include <deque>

int main()
{

	std::cout << "===PDF===\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// TESTS
	try
	{
		std::cout << "===Test 1===\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(1); // cannot add 6th element as max size is 5

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "===Test 2===\n";
		Span sp = Span(1);
		sp.addNumber(6);

		std::cout << sp.shortestSpan() << std::endl; // cannot get any span with only 1 element
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "===Test 3===\n"; // test int_max and int_min
		Span sp = Span(2);
		sp.addNumber(2147483647);
		sp.addNumber(-2147483648);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "===Test 4===\n"; // test range of iterators
		Span sp = Span(5);
		std::vector<int> numbersToAdd;
		numbersToAdd.push_back(1);
		numbersToAdd.push_back(5);
		numbersToAdd.push_back(4);

		sp.addNumber(3);
		sp.addManyNumbers(numbersToAdd.begin(), numbersToAdd.end());
		sp.addNumber(2);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "===Test 5===\n"; // test range of iterators, but not enough space
		Span sp = Span(3);
		std::deque<int> numbersToAdd;
		numbersToAdd.push_back(1);
		numbersToAdd.push_back(5);
		numbersToAdd.push_back(4);

		sp.addNumber(3);
		sp.addManyNumbers(numbersToAdd.begin(), numbersToAdd.end());
		sp.addNumber(2);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "===Test 6===\n"; // test at least 10,000 numbers
		Span sp = Span(100000);
		sp.addRandomNumbers(100000);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}