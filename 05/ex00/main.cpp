#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== TEST 1 ===\n\n";
	try
	{
		Bureaucrat noname;
		std::cout << noname;
		noname.incrementGrade();
		std::cout << noname;
		noname.decrementGrade();
		std::cout << noname;
		noname.decrementGrade();
		std::cout << noname;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 2 ===\n\n";
	try
	{
		Bureaucrat john("John", 2);
		std::cout << john;
		john.incrementGrade();
		std::cout << john;
		john.incrementGrade();
		std::cout << john;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 3 ===\n\n";
	try
	{
		Bureaucrat mark("Mark", -27);
		std::cout << mark;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 4 ===\n\n";
	try
	{
		Bureaucrat dan("Dan", 0);
		std::cout << dan;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 5 ===\n\n";
	try
	{
		Bureaucrat mike("Mike", 151);
		std::cout << mike;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 6 ===\n\n";
	try
	{
		Bureaucrat jan("Jan", 122);
		Bureaucrat jan_copy(jan);
		std::cout << jan;
		std::cout << jan_copy;
		jan_copy.decrementGrade();
		std::cout << jan;
		std::cout << jan_copy;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}