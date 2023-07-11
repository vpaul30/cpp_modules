#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	void beSigned(Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream &COUT, Form &form);

#endif