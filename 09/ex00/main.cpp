#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Should be 1 argument (input file).\n";
		return 0;
	}

	BitcoinExchange btc(argv[1]);

	btc.run();
	return 0;
}