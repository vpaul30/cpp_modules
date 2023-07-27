#include "AForm.hpp"

AForm::AForm()
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm default constructor.\n";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
	else if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	std::cout << "AForm constructor with parameters called.\n";
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)	
{
	std::cout << "Form copy constructor called.\n";
}

AForm::~AForm()
{
	std::cout << "Form destructor called.\n";
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Form assignment operator called.\n";
	// it's not going to do anything
	// as almost all of the Form's
	// members are constants
	_signed = other._signed;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed!";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (_signed == false)
		throw FormNotSigned();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction();
}


std::ostream &operator<<(std::ostream &COUT, AForm &aform)
{
	std::cout << "=== AForm ===\n";
	std::cout << "Name: " << aform.getName() << std::endl;
	std::cout << "Signed: ";
	if (aform.getSigned())
		std::cout << "true\n";
	else
		std::cout << "false\n";
	std::cout << "Grade to Sign: " << aform.getGradeToSign() << std::endl;
	std::cout << "Grade to Execute: " << aform.getGradeToExec() << std::endl;
	std::cout << "============\n";

	return COUT;
}