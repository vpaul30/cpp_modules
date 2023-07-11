#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void executeAction() const;

};


#endif