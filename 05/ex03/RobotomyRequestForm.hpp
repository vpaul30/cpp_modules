#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void executeAction() const;

};


#endif