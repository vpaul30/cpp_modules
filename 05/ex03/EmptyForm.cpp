#include "EmptyForm.hpp"

EmptyForm::EmptyForm()
	: AForm("EmptyForm", 150, 150), _target("default")
{
	std::cout << "EmptyForm default constructor called.\n";
}

EmptyForm::EmptyForm(std::string target)
	: AForm("EmptyForm", 150, 150), _target(target)
{
	std::cout << "EmptyForm constructor called.\n";
}

EmptyForm::EmptyForm(const EmptyForm &other)
	: AForm("EmptyForm", 150, 150), _target(other._target)
{
	std::cout << "EmptyForm copy constructor called.\n";
}

EmptyForm &EmptyForm::operator=(const EmptyForm &other)
{
	std::cout << "EmptyForm assignement operator called.\n";
	_target = other._target;
	return *this;
}

EmptyForm::~EmptyForm()
{
	std::cout << "EmptyForm destructor called.\n";
}


void EmptyForm::executeAction() const
{
	std::cout << "<empty form>\n";
}