#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>


class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN &operator=(const RPN &other);

	void run(std::string input);
	bool calculate(char op);

private:
	std::stack<float> _stack;

};

#endif