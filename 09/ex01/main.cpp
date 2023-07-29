#include <iostream>
#include "RPN.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "There should be 1 parameter.\n";
		return 0;
	}

	RPN rpn;
	rpn.run(argv[1]);


	return 0;
}