#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <algorithm>

/*
readline from text.txt, validate it
if line is valid -> get the value from DB for that line
print result

*/

class BitcoinExchange
{
private:
	std::string _inputFile;
	std::map<int, float> database;

	bool validateDBLine(std::string &line);
	bool validateInputLine(std::string &line);
	int	countCharsInLine(std::string &line, char c);
	int getDate(std::string &date);
	float getValue(std::string &value);
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