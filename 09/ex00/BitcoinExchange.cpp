#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called.\n";
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
	std::cout << "BitcoinExchange constructor called.\n";
}	
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) // TODO copy map
{
	std::cout << "BitcoinExchange copy constructor called.\n";
	*this = other;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called.\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) // TODO copy map
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
	while (std::getline(dbFile, line))
	{
		// if (i > 3) break; // only going through first 3 lines for debug
		i++; // debug
		if (!validateDBLine(line)) // mistake in database
			return;
	}
	// for (std::map<int, float>::iterator it = database.begin(); it != database.end(); it++)
	// {
	// 	std::cout << "key: " << it->first << std::endl;
	// 	std::cout << "value: " << it->second << std::endl;
	// }
	// std::cout << "database.size() = " << database.size() << std::endl;

	// 2. userInput
	std::ifstream inputFile;
	inputFile.open(_inputFile);
	if (!inputFile.good())
	{
		std::cerr << "Error: Input File: cannot open file.\n";
		return;
	}
	if (std::getline(inputFile, line) && line != "date | value")
	{
		std::cerr << "Error: Input File: incorrect first line\n";
		return;
	}
	while (std::getline(inputFile, line))
	{
		/*
			validate line:
				if no delimiter -> bad input => line
				check date
					if mistake in date -> wrong date
				check value (0-1000)
					if value is negative -> not a positive number
					if value is > 1000 -> too high a number
			look database for the key,
				if key is smaller than database.begin() -> use database.begin()
				if key is higher than database.end() - 1 -> use database.end() - 1
				if no exect key found -> use lower_bound() ???
		*/
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

	int date_num = getDate(date);
	if (date_num == -1)
	{
		std::cerr << "Error: DB: wrong date.\n";
		return false;
	}
	float value_num = getValue(value); // TODO
	if (value_num == -1)
	{
		std::cerr << "Error: DB: wrong value.\n";
		return false;
	}

	database.insert(std::pair<int, float>(date_num, value_num)); // add element to map
	return true;
}

bool BitcoinExchange::validateInputLine(std::string &line)
{
	if (line.empty())
		return false; // Werror
	return true;
}


bool extractYear(std::string &date, int &date_num)
{
	std::string year = date.substr(0, date.find('-'));
	// std::cout << "year = " << year << std::endl;
	if (year.length() != 4)
		return false;
	for (size_t i = 0; i < year.length(); i++)
		if (!std::isdigit(year[i]))
			return false;
	int year_num = atoi(year.c_str());
	if (year_num < 1000)
		return false;
	date_num += year_num * 10000;
	return true;
}

bool extractMonth(std::string &date, int &date_num)
{
	std::string month = date.substr(date.find('-') + 1,
									date.find_last_of('-') - date.find('-') - 1);
	// std::cout << "month = " << month << std::endl;
	if (month.length() != 2)
		return false;
	for (size_t i = 0; i < month.length(); i++)
		if (!std::isdigit(month[i]))
			return false;
	int month_num = atoi(month.c_str());
	if (month_num < 1 || month_num > 12)
		return false;
	date_num += month_num * 100;
	
	return true;
}

bool extractDay(std::string &date, int &date_num)
{
	std::string day = date.substr(date.find_last_of('-') + 1, date.length() - 1 - date.find_last_of('-'));
	// std::cout << "day = " << day << std::endl;
	if (day.length() != 2)
		return false;
	for (size_t i = 0; i < day.length(); i++)
		if (!std::isdigit(day[i]))
			return false;
	int day_num = atoi(day.c_str());
	if (day_num < 1 || day_num > 31)
		return false;
	date_num += day_num;
	
	return true;
}

int BitcoinExchange::getDate(std::string &date)
{
	// year * 10000 + month * 100 + day
	int date_num = 0;
	// check for 2 occurrences of '-'
	if (std::count(date.begin(), date.end(), '-') != 2)
		return -1;
	// year
	if (!extractYear(date, date_num))
		return -1;
	// month
	if (!extractMonth(date, date_num))
		return -1;
	// day
	if (!extractDay(date, date_num))
		return -1;
	
	return date_num;
}

float BitcoinExchange::getValue(std::string &value)
{
	// only positive and can be fractional | can be negative to throw error for userInput
	if (std::count(value.begin(), value.end(), '.') > 1 || value[0] == '.' || value[value.length() - 1] == '.')
		return -1;
	for (unsigned int i = 0; i < value.length(); i++)
		if (!std::isdigit(value[i]) && value[i] != '.')
			return -1;
	return atof(value.c_str());
}
