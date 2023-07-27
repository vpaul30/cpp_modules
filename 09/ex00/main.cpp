#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	std::string input = argv[1];
	BitcoinExchange btc(input);
	btc.run();
	return 0;
}