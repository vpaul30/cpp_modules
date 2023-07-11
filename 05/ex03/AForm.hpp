#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class FormNotSigned : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;
	virtual void executeAction() const = 0;

};

std::ostream &operator<<(std::ostream &COUT, AForm &form);

#endif