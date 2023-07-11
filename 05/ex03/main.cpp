#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "EmptyForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "=== TEST 1 ===\n\n";
	{
		AForm *form = NULL;
		try
		{
			Bureaucrat john("John", 5);
			Intern intern;

			form = intern.makeForm("WrongForm", "WrongTarget");

			john.signForm(*form);
			john.executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (form != NULL)
			delete form;
	}

	std::cout << "\n=== TEST 2 ===\n\n";
	{
		AForm *form = NULL;
		try
		{
			Bureaucrat john("John", 5);
			Intern intern;

			form = intern.makeForm("PresidentialPardonForm", "Bob");
			// form = intern.makeForm("RobotomyRequestForm", "Mike");
			// form = intern.makeForm("ShrubberyCreationForm", "Garden");

			john.signForm(*form);
			john.executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (form != NULL)
			delete form;
	}
}