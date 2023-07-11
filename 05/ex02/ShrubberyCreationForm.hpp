#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void executeAction() const;

};

#endif