#ifndef INTERN_HPP
#define	INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "EmptyForm.hpp"

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern &operator=(const Intern &other);

	AForm *makeForm(std::string formName, std::string formTarget);

};

#endif