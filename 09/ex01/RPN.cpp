#include "RPN.hpp"

RPN::RPN()
{
	// std::cout << "Default constructor called.\n";
}

RPN::RPN(const RPN &other)
{
	// std::cout << "Constructor called.\n";
	*this = other;
}

RPN::~RPN()
{
	// std::cout << "Destructor called.\n";
}

RPN &RPN::operator=(const RPN &other)
{
	// std::cout << "Assignment operator called.\n";
	if (this == &other)
		return *this;
	_stack = other._stack;
	return *this;
}

void RPN::run(std::string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (std::isspace(input[i]))
			continue;
		if (std::isdigit(input[i]))
		{
			_stack.push(input[i] - '0');
			continue;
		}
		switch (input[i])
		{
		case '+':
			if (!calculate('+'))
				return;
			break;
		case '-':
			if (!calculate('-'))
				return;
			break;
		case '*':
			if (!calculate('*'))
				return;
			break;
		case '/':
			if (!calculate('/'))
				return;
			break;
		default:
			std::cerr << "Error\n";
			return;
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error\n";
		return;
	}
	std::cout << _stack.top() << std::endl;
}

bool RPN::calculate(char op)
{
	float num1, num2;
	switch (op)
	{
	case '+':
		if (_stack.size() < 2)
		{
			std::cerr << "Should be 2 numbers before operator.\n";
			return false;
		}
		num2 = _stack.top();
		_stack.pop();
		num1 = _stack.top();
		_stack.pop();
		_stack.push(num1 + num2);
		break;
	case '-':
		if (_stack.size() < 2)
		{
			std::cerr << "Should be 2 numbers before operator.\n";
			return false;
		}
		num2 = _stack.top();
		_stack.pop();
		num1 = _stack.top();
		_stack.pop();
		_stack.push(num1 - num2);
		break;
	case '*':
		if (_stack.size() < 2)
		{
			std::cerr << "Should be 2 numbers before operator.\n";
			return false;
		}
		num2 = _stack.top();
		_stack.pop();
		num1 = _stack.top();
		_stack.pop();
		_stack.push(num1 * num2);
		break;
	case '/':
		if (_stack.size() < 2)
		{
			std::cerr << "Should be 2 numbers before operator.\n";
			return false;
		}
		num2 = _stack.top();
		_stack.pop();
		num1 = _stack.top();
		_stack.pop();
		if (num2 == 0)
		{
			std::cerr << "Division by 0.\n";
			return false;
		}
		_stack.push(num1 / num2);
		break;
	default:
		break;
	}

	return true;
}
