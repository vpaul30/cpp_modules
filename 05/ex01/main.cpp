#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== TEST 1 ===\n\n";
	try
	{
		Bureaucrat john("John", 25);
		Form form("Test", 75, 50);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 2 ===\n\n";
	try
	{
		Bureaucrat john("John", 25);
		Form form("Test", 0, 50);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 3 ===\n\n";
	try
	{
		Bureaucrat john("John", 25);
		Form form("Test", 151, 50);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 4 ===\n\n";
	try
	{
		Bureaucrat john("John", 25);
		Form form("Test", 75, 0);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 5 ===\n\n";
	try
	{
		Bureaucrat john("John", 25);
		Form form("Test", 75, 151);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== TEST 6 ===\n\n";
	try
	{
		Bureaucrat john("John", 25);
		Form form("Test", 15, 25);
		std::cout << form;
		john.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}