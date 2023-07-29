#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange default constructor called.\n";
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
	// std::cout << "BitcoinExchange constructor called.\n";
}	
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) // TODO copy map
{
	// std::cout << "BitcoinExchange copy constructor called.\n";
	*this = other;
}
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor called.\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) // TODO copy map
{
	// std::cout << "BitcoinExchange assignment operator called.\n";
	if (this == &other)
		return *this;
	_inputFile = other._inputFile;
	_database = other._database;

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
		std::cerr << "Error: DB: incorrect first line.\n";
		return;
	}
	while (std::getline(dbFile, line))
	{
		if (!validateDbLine(line)) // mistake in database
			return;
	}
	if (_database.size() < 1)
	{
		std::cerr << "Error: DB: empty database.\n";
		return;
	}

	// 2. userInput
	std::ifstream inputFile;
	inputFile.open(_inputFile.c_str()); // check if .c_str() is needed!!!
	if (!inputFile.good())
	{
		std::cerr << "Error: Input File: cannot open file.\n";
		return;
	}
	if (std::getline(inputFile, line) && line != "date | value")
	{
		std::cerr << "Error: Input File: incorrect first line.\n";
		return;
	}
	while (std::getline(inputFile, line))
		validateInputLine(line);
}

bool BitcoinExchange::validateDbLine(std::string &line)
{
	size_t delimPos = line.find(',');
	if (delimPos == std::string::npos)
	{
		std::cerr << "Error: DB: no delimiter in line.\n";
		return false;
	}
	std::string date = line.substr(0, delimPos);
	std::string value = line.substr(delimPos + 1, line.length() - 1 - delimPos);
	int date_num = getDate(date);
	if (date_num == -1)
	{
		std::cerr << "Error: DB: wrong date.\n";
		return false;
	}
	float value_num = getValue(value);
	if (value_num < 0)
	{
		std::cerr << "Error: DB: wrong value.\n";
		return false;
	}

	_database.insert(std::pair<int, float>(date_num, value_num)); // add element to map
	return true;
}

bool BitcoinExchange::validateInputLine(std::string &line)
{
	size_t delimPos = line.find(" | ");
	if (delimPos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	std::string date = line.substr(0, delimPos);
	std::string value = line.substr(delimPos + 3, line.length() - delimPos);

	int date_num = getDate(date);
	if (date_num == -1)
	{
		std::cerr << "Error: wrong date.\n";
		return false;
	}
	float value_num = getValue(value);
	if (value_num == -1)
	{
		std::cerr << "Error: wrong value.\n";
		return false;
	}
	else if (value_num == -2)
	{
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	else if (value_num > 1000)
	{
		std::cerr << "Error: too large a number.\n";
		return false;
	}

	std::map<int, float>::iterator it;
	it = _database.lower_bound(date_num);
	if (it->first == date_num)
	{
		std::cout << date << " => " << value_num << " = ";
		std::cout << value_num * it->second << std::endl;
	}
	// else if (it == _database.end())
	// {
	// 	std::cout << date << " => " << value_num << " = ";
	// 	std::cout << value_num * (--it)->second << std::endl;
	// }
	else
	{
		if (it == _database.begin())
		{
			std::cout << date << " => " << value_num << " = ";
			std::cout << "No bitcoin data" << std::endl;
		}
		else
		{
			std::cout << date << " => " << value_num << " = ";
			std::cout << value_num * (--it)->second << std::endl;
		}
	}
	return true;
}

bool BitcoinExchange::extractYear(std::string &date, int &date_num)
{
	std::string year = date.substr(0, date.find('-'));
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

bool BitcoinExchange::extractMonth(std::string &date, int &date_num)
{
	std::string month = date.substr(date.find('-') + 1,
									date.find_last_of('-') - date.find('-') - 1);
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

bool BitcoinExchange::extractDay(std::string &date, int &date_num)
{
	std::string day = date.substr(date.find_last_of('-') + 1, date.length() - 1 - date.find_last_of('-'));
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
	if (!extractYear(date, date_num))
		return -1;
	if (!extractMonth(date, date_num))
		return -1;
	if (!extractDay(date, date_num))
		return -1;
	
	return date_num;
}

float BitcoinExchange::getValue(std::string &value)
{
	// -1 -> wrong value (not a real number)
	// -2 -> negative number (needed for userInput error)
	if (std::count(value.begin(), value.end(), '.') > 1 || value[0] == '.' || value[value.length() - 1] == '.')
		return -1;
	unsigned int i = 0;
	if (value[i] == '-')
		i++;
	for (; i < value.length(); i++)
		if (!std::isdigit(value[i]) && value[i] != '.')
			return -1;
	if (value[0] == '-')
		return -2;
	return atof(value.c_str());
}
