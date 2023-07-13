#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called.\n";
}
BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
	std::cout << "BitcoinExchange constructor called.\n";
}	
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange copy constructor called.\n";
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called.\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange assignment operator called.\n";
	return *this;
}

void BitcoinExchange::run()
{
	std::ifstream file;
	std::string line;
	file.open(_inputFile);
	if (!file.good())
		return; // cannot open file

	if (std::getline(file, line) && line != "date | value")
		return;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
		if (!validateLine(line))
		{
			std::cout << "invalid line\n";
		}
		// if line is valid -> get the value from DB
		// else -> print Error: ...
		std::cout << "=====\n";
	}
}

bool BitcoinExchange::validateLine(std::string &line)
{
	if (countCharsInLine(line, '|') != 1)
	{
		return false; // bad input
	}
	std::string date = line.substr(0, line.find('|'));
	std::cout << "date: " << date << ".\n";
	
	// try
	// {
	// 	validateDate(date);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Error: " << e.what();
	// 	return false;
	// }


	// if (!validateDate(date))
		// return false; // throw wrong date


	std::string value = line.substr(line.find('|') + 1, line.length() - 1);
	std::cout << "value: " << value << ".\n";
	// validateValue(value); // 
	return true;
}

int	BitcoinExchange::countCharsInLine(std::string &line, char c)
{
	int c_counter = 0;

	for (int i = 0; i < line.length(); i++)
		if (line[i] == c)
			c_counter++;
	return c_counter;
}
// 2011-01-03 (space at the end)
bool BitcoinExchange::validateDate(std::string &date)
{
	if (date[date.length() - 1] != ' ')
		return false;

	if (countCharsInLine(date, '-') != 2)
		return false;

	// YEAR
	std::string yearStr = date.substr(0, date.find_first_of('-'));
	std::cout << "yearStr: " << yearStr << std::endl;
	for (int i = 0; i < yearStr.length(); i++)
		if (!std::isdigit(yearStr[i]))
			return false;
	if (std::stoi(yearStr) < 1000 || std::stoi(yearStr) > 9999)
		return false;
	// MONTH
	std::string monthStr = date.substr(date.find_first_of('-') + 1,
		date.find_last_of('-') - date.find_first_of('-') - 1);
	std::cout << "monthStr: " << monthStr << std::endl;
	if (std::stoi(monthStr) < 1 || std::stoi(monthStr) > 12)
		return false;
	// DAY
	std::string dayStr = date.substr(date.find_last_of('-') + 1, date.length() - 1);
	std::cout << "dayStr: " << dayStr << std::endl;
	if (std::stoi(dayStr) < 1 || std::stoi(dayStr) > 31)
		return false;
	return true;
}

bool BitcoinExchange::validateValue(std::string &value)
{
	return true;
}











