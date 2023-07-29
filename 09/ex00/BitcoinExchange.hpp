#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <algorithm>

class BitcoinExchange
{
private:
	std::string _inputFile;
	std::map<int, float> _database;

	bool validateDbLine(std::string &line);
	bool validateInputLine(std::string &line);
	int getDate(std::string &date);
	float getValue(std::string &value);
	bool extractYear(std::string &date, int &date_num);
	bool extractMonth(std::string &date, int &date_num);
	bool extractDay(std::string &date, int &date_num);


public:
	BitcoinExchange();
	BitcoinExchange(std::string inputFile);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void run();
};

#endif