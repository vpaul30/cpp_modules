#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

/*
readline from text.txt, validate it
if line is valid -> get the value from DB for that line
print result

*/

class BitcoinExchange
{
private:
	std::string _inputFile;

	bool validateLine(std::string &line);
	int	countCharsInLine(std::string &line, char c);
	bool validateDate(std::string &date);
	bool validateValue(std::string &date);
	void printError(std::string errMsg);

public:
	BitcoinExchange();
	BitcoinExchange(std::string inputFile);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void run();
};

#endif