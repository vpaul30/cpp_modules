#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called.\n";
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called.\n";
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called.\n";
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called.\n";
	if (this == &other)
		return *this;

	return *this;
}

AForm	*makePresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[] = {	"PresidentialPardonForm",
								"RobotomyRequestForm",
								"ShrubberyCreationForm"	};
	AForm *(*makeFormFuncs[])(std::string target) = {	&makePresidential,
														&makeRobotomy,
														&makeShrubbery	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates a " << formName << ".\n";
			return makeFormFuncs[i](formTarget);
		}
	}

	std::cout << "Intern cannot create a " << formName << ", so he left the form empty.\n";
	// return new EmptyForm(formTarget);
	return NULL;
}