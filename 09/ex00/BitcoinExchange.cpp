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
	*this = other;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called.\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange assignment operator called.\n";
	if (this == &other)
		return *this;
	return *this;
}

/*
	1. DB
		open file
		read every line,
		validate line (date,value)
			* true -> add <date, value> to map
			* false -> throw MistakeInDatabaseException() (catch in main)
	
	2. userInput
		open file
		read every line,
		validate line (date | value)
			* true -> print "date => amount = result"
			* false -> print "Error: ..."
*/
void BitcoinExchange::run()
{
	// 1. DB
	std::ifstream dbFile;
	dbFile.open("data.csv");
	if (!dbFile.good())
	{
		std::cerr << "Error: DB: cannot open file.\n";
		return;
	}
	std::string line;
	if (std::getline(dbFile, line) && line != "date,exchange_rate")
	{
		std::cerr << "Error: DB: incorrect first line\n";
		return;
	}
	int i = 0; // debug
	while (std::getline(dbFile, line) && i < 3) // only going through first 3 lines for debug
	{
		std::cout << line << std::endl;
		if (!validateDBLine(line)) // mistake in database
			return;
		i++; // debug
	}

}

bool BitcoinExchange::validateDBLine(std::string &line)
{
	size_t delimPos = line.find(',');
	if (delimPos == std::string::npos)
	{
		std::cerr << "Error: DB: no delimiter in line.\n";
		return false;
	}
	std::string date = line.substr(0, delimPos);
	std::string value = line.substr(delimPos + 1, line.length() - 1);

	// std::cout << "coma pos = " << delimPos << std::endl;
	// std::cout << "date = " << date << "." << std::endl;
	// std::cout << "value = " << value << std::endl;

	int date_num = getDate(date);
	if (date_num == -1)
	{
		std::cerr << "Error: DB: wrong date.\n";
		return false;
	}
	int value_num = getValue(value); // TODO
	if (date_num == -1)
	{
		std::cerr << "Error: DB: wrong value.\n";
		return false;
	}
	// add element to map
	return true;
}

int BitcoinExchange::getDate(std::string &date)
{
	// year * 1000 + month * 100 + day * 10
	int date_num = 0;
	// check for 2 occurrences of '-'
	if (std::count(date.begin(), date.end(), '-') != 2)
		return -1;
	// year	
	std::string year = date.substr(0, date.find('-'));
	// std::cout << "year = " << year << std::endl;
	bool allDigits = true;
	for (int i = 0; i < year.length(); i++)
		if (!std::isdigit(year[i]))
			allDigits = false;
	if (year.length() != 4 || !allDigits)
		return -1;
	date_num += atoi(year.c_str()) * 10000;
	std::cout << "date_num = " << date_num << std::endl;

	// month
	
	return date_num;
}

int BitcoinExchange::getValue(std::string &value)
{
	return -1;
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



// int	BitcoinExchange::countCharsInLine(std::string &line, char c)
// {
// 	int c_counter = 0;

// 	for (int i = 0; i < line.length(); i++)
// 		if (line[i] == c)
// 			c_counter++;
// 	return c_counter;
// }
// // 2011-01-03 (space at the end)
// bool BitcoinExchange::validateDate(std::string &date)
// {
// 	if (date[date.length() - 1] != ' ')
// 	{
// 		printError("no space after date");
// 		return false;
// 	}

// 	if (countCharsInLine(date, '-') != 2)
// 	{
// 		printError("bad date");
// 		return false;
// 	}

// 	// YEAR
// 	std::string yearStr = date.substr(0, date.find_first_of('-'));
// 	// std::cout << "yearStr: " << yearStr << std::endl;
// 	if (yearStr.empty())
// 	{
// 		printError("no year");
// 		return false;
// 	}
// 	for (int i = 0; i < yearStr.length(); i++)
// 		if (!std::isdigit(yearStr[i]))
// 		{
// 			printError("year must be a number");
// 			return false;
// 		}
// 	if (atoi(yearStr.c_str()) < 1000 || atoi(yearStr.c_str()) > 9999)
// 	{
// 		printError("year must be in range from 1000 to 9999");
// 		return false;
// 	}
// 	// MONTH
// 	std::string monthStr = date.substr(date.find_first_of('-') + 1,
// 		date.find_last_of('-') - date.find_first_of('-') - 1);
// 	// std::cout << "monthStr: " << monthStr << std::endl;
// 	if (monthStr.empty())
// 	{
// 		printError("no month");
// 		return false;
// 	}
// 	for (int i = 0; i < monthStr.length(); i++)
// 		if (!std::isdigit(monthStr[i]))
// 		{
// 			printError("month must be a number");
// 			return false;
// 		}
// 	if (atoi(monthStr.c_str()) < 1 || atoi(monthStr.c_str()) > 12)
// 	{
// 		printError("month must be in range from 1 to 12");
// 		return false;
// 	}
// 	// DAY
// 	std::string dayStr = date.substr(date.find_last_of('-') + 1, date.length() - 1);
// 	// std::cout << "dayStr: " << dayStr << std::endl;
// 	// dayStr.pop_back(); // remove space at the end
// 	if (dayStr.empty())
// 	{
// 		printError("no day");
// 		return false;
// 	}
// 	for (int i = 0; i < dayStr.length(); i++)
// 		if (!std::isdigit(dayStr[i]))
// 		{
// 			printError("day must be a number");
// 			return false;
// 		}
// 	if (atoi(dayStr.c_str()) < 1 || atoi(dayStr.c_str()) > 31)
// 	{
// 		printError("day must be in range from 1 to 31");
// 		return false;
// 	}
// 	return true;
// }

// bool BitcoinExchange::validateValue(std::string &value)
// {
// 	return true;
// }

// void BitcoinExchange::printError(std::string errMsg)
// {
// 	std::cout << "Error: " << errMsg << std::endl;
// }








