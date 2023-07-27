#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called with name and grade.\n";
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	std::cout << "Bureaucrat copy constructor called.\n";
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called.\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called.\n";
	_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << "Bureaucrat grade incremented.\n";
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << "Bureaucrat grade decremented.\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned() == true)
	{
		std::cout << form.getName() << " is already signed.\n";
		return;
	}
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << _name << " couldn't sign " << form.getName() << ": ";
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat " << _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << ".\n";
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << ": ";
		std::cout << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &COUT, Bureaucrat &bureaucrat)
{
	std::cout << "=== Bureaucrat ===\n";
	std::cout << "Name: " << bureaucrat.getName() << std::endl;
	std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
	std::cout << "==================\n";
	return COUT;
}
