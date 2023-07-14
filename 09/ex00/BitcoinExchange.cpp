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
		if (!validateLine(line))
		{
			// std::cout << "invalid line\n";
			continue;
		}
		std::cout << line << std::endl;
		// if line is valid -> get the value from DB
		// else -> print Error: ...
		std::cout << "=====\n";
	}
}

// bool BitcoinExchange::validateLine(std::string &line)
// {
// 	if (countCharsInLine(line, '|') != 1)
// 	{
// 		printError("bad input => " + line);
// 		return false;
// 	}
// 	std::string date = line.substr(0, line.find('|'));
// 	std::string value = line.substr(line.find('|') + 1, line.length() - 1);
// 	if (date.empty() || value.empty())
// 	{
// 		printError("bad input => " + line);
// 		return false;
// 	}
// 	// std::cout << "date: " << date << ".\n";
// 	if (!validateDate(date))
// 		return false;
// 	// std::cout << "value: " << value << ".\n";
// 	if (!validateValue(value))
// 		return false;


// 	return true;
// }

bool BitcoinExchange::validateLine(std::string &line)
{
	// check for delim (" | " or ',')
	int pipeDelimPos = line.find(" | ");
	int comaDelimPos = line.find(',');

	std::cout << "pipe pos = " << pipeDelimPos << std::endl;
	std::cout << "coma pos = " << comaDelimPos << std::endl;



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
	{
		printError("no space after date");
		return false;
	}

	if (countCharsInLine(date, '-') != 2)
	{
		printError("bad date");
		return false;
	}

	// YEAR
	std::string yearStr = date.substr(0, date.find_first_of('-'));
	// std::cout << "yearStr: " << yearStr << std::endl;
	if (yearStr.empty())
	{
		printError("no year");
		return false;
	}
	for (int i = 0; i < yearStr.length(); i++)
		if (!std::isdigit(yearStr[i]))
		{
			printError("year must be a number");
			return false;
		}
	if (std::stoi(yearStr) < 1000 || std::stoi(yearStr) > 9999)
	{
		printError("year must be in range from 1000 to 9999");
		return false;
	}
	// MONTH
	std::string monthStr = date.substr(date.find_first_of('-') + 1,
		date.find_last_of('-') - date.find_first_of('-') - 1);
	// std::cout << "monthStr: " << monthStr << std::endl;
	if (monthStr.empty())
	{
		printError("no month");
		return false;
	}
	for (int i = 0; i < monthStr.length(); i++)
		if (!std::isdigit(monthStr[i]))
		{
			printError("month must be a number");
			return false;
		}
	if (std::stoi(monthStr) < 1 || std::stoi(monthStr) > 12)
	{
		printError("month must be in range from 1 to 12");
		return false;
	}
	// DAY
	std::string dayStr = date.substr(date.find_last_of('-') + 1, date.length() - 1);
	// std::cout << "dayStr: " << dayStr << std::endl;
	dayStr.pop_back(); // remove space at the end
	if (dayStr.empty())
	{
		printError("no day");
		return false;
	}
	for (int i = 0; i < dayStr.length(); i++)
		if (!std::isdigit(dayStr[i]))
		{
			printError("day must be a number");
			return false;
		}
	if (std::stoi(dayStr) < 1 || std::stoi(dayStr) > 31)
	{
		printError("day must be in range from 1 to 31");
		return false;
	}
	return true;
}

bool BitcoinExchange::validateValue(std::string &value)
{
	return true;
}

void BitcoinExchange::printError(std::string errMsg)
{
	std::cout << "Error: " << errMsg << std::endl;
}








