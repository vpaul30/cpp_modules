#include "Form.hpp"

Form::Form()
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default constructor.\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	else if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	std::cout << "Form constructor with parameters called.\n";
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)	
{
	std::cout << "Form copy constructor called.\n";
}

Form::~Form()
{
	std::cout << "Form destructor called.\n";
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called.\n";
	// it's not going to do anything
	// as almost all of the Form's
	// members are constants
	_signed = other._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream &operator<<(std::ostream &COUT, Form &form)
{
	std::cout << "=== Form ===\n";
	std::cout << "Name: " << form.getName() << std::endl;
	std::cout << "Signed: ";
	if (form.getSigned())
		std::cout << "true\n";
	else
		std::cout << "false\n";
	std::cout << "Grade to Sign: " << form.getGradeToSign() << std::endl;
	std::cout << "Grade to Execute: " << form.getGradeToExec() << std::endl;
	std::cout << "============\n";

	return COUT;
}