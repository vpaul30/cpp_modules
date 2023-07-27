#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "=== TEST 1 ===\n\n";
	try
	{
		Bureaucrat john("John", 5);
		PresidentialPardonForm form("Bob");

		std::cout << form;
		john.signForm(form);
		// std::cout << form;

		john.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=== TEST 2 ===\n\n";
	try
	{
		Bureaucrat john("John", 45);
		RobotomyRequestForm form("Bob");

		std::cout << form;
		john.signForm(form);
		// std::cout << form;

		john.executeForm(form);
		john.executeForm(form);
		john.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=== TEST 3 ===\n\n";
	try
	{
		Bureaucrat john("John", 137);
		ShrubberyCreationForm form("Garden");
		
		std::cout << form;
		john.signForm(form);
		// std::cout << form;
	
		john.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}