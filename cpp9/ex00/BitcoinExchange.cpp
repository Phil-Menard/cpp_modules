#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

const char* BitcoinExchange::FileNotOpenException::what() const throw()
{
	return "A problem occured while opening the file.";
}

void BitcoinExchange::retrieveDataFile()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		throw FileNotOpenException();
	}

	std::string line;

	std::getline(file, line, '\n');
	while(getline(file, line))
	{
		std::string date;
		float exchange_rate;
		int i = 0;

		for (; line[i] != ',' ; i++);
		date = line.substr(0, i);
		exchange_rate = strtof(line.substr(i + 1, line.size()).c_str(), NULL);
		data.insert(std::pair<std::string, float>(date, exchange_rate));
	}
}

void getDate(std::string date, int & year, int & month, int & day)
{
	size_t found = date.find("-");
	if (found == std::string::npos)
		std::cout << "Invalid format." << std::endl;
	year = atoi(date.substr(0, found).c_str());

	std::string date2 = date.substr(found + 1, date.size());
	found = date2.find("-");
	if (found == std::string::npos)
		std::cout << "Invalid format." << std::endl;

	month = atoi(date2.substr(0, found).c_str());
	day = atoi(date2.substr(found + 1, date2.size()).c_str());
}

int checkDate(int year, int month, int day)
{
	int daysPerMonths[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 2009)
	{
		std::cout << "Error: The year should at least start from 2009." << std::endl;
		return 1;
	}
	if ((month < 1 || month > 12))
	{
		std::cout << "This month does not exist" << std::endl;
		return 1;
	}

	//check leap years
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				daysPerMonths[1] = 29;
			else
				daysPerMonths[1] = 28;
		}
	}
	if (day > daysPerMonths[month - 1])
	{
		std::cout << "This day does not exist" << std::endl;
		return 1;
	}
	return 0;
}

int checkValue(std::string value)
{
	float a = strtof(value.c_str(), NULL);
	if (a < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (a > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 1;
	}
	return 0;
}

void checkLine(std::string line)
{
	int i = 0;
	int year,month,day;
	for (;line[i] && line[i] != '|' ; i++);
	if (i >= static_cast<int>(line.size()))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, i);

	while(line[i] && !isdigit(line[i]))
		i++;
	int j = i;
	if (line[i - 1] == '-')
		i--;
	while(line[j] && (isdigit(line[i]) || line[i] == '.'))
		j++;
	if (j < static_cast<int>(line.size()-1))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	//CHECK DATE
	getDate(date, year, month, day);
	// std::cout << "year : " << year << " | month : " << month << " | day : " << day << std::endl;
	if (checkDate(year, month, day) == 1)
		return;

	//CHECK VALUE
	std::string value = line.substr(i, j);
	std::cout << "value : " << value << std::endl;
	if(checkValue(value) == 1)
		return;
}

void BitcoinExchange::displayBtc(char* & file)
{
	std::ifstream outfile(file);
	if (!outfile.is_open())
	{
		throw FileNotOpenException();
	}

	std::string line;
	getline(outfile, line);
	size_t found = line.find("date");
	if (found == std::string::npos)
		checkLine(line);
	while(getline(outfile, line))
	{
		checkLine(line);
	}
}

void BitcoinExchange::printDataMap()
{
	std::map<std::string, float>::iterator it = this->data.begin();

	for (; it != this->data.end(); ++it)
		std::cout << it->first << " : " << it->second << std::endl;
}
