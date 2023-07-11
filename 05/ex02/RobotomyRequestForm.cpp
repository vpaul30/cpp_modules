#include "RobotomyRequestForm.hpp"
#include "cstdlib"
#include "ctime"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called.\n";
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called.\n";
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm("RobotomyRequestForm", 72, 45), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called.\n";
	srand(time(NULL));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignement operator called.\n";
	_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called.\n";
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drrrrr...ddrrrr... (some drilling noises).\n";
	int rand_res = rand() % 2;
	if (rand_res)
		std::cout << _target << " has been robotomized.\n";
	else
		std::cout << _target << " has not been robotomized.\n";
}