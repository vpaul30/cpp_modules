#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
private:
	std::string _inputFile;
	std::map<int, double> _database;

	bool validateDbLine(std::string &line);
	bool validateInputLine(std::string &line);
	int getDate(std::string &date);
	double getValue(std::string &value);
	bool extractYear(std::string &date, int &date_num);
	bool extractMonth(std::string &date, int &date_num);
	bool extractDay(std::string &date, int &date_num);
	void printValue(double amount, double price);


public:
	BitcoinExchange();
	BitcoinExchange(std::string inputFile);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void run();
};

#endif