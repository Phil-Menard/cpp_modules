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
	if (year < 2009)
	{
		std::cout << "Error: the year should at least start from 2009." << std::endl;
		return 1;
	}
	if ((month < 1 || month > 12))
	{
		std::cout << "Error: this month does not exist." << std::endl;
		return 1;
	}
	int february = 28;
	//check leap years
	if (year % 4 == 0)
	{
		february = 29;
		if (year % 100 == 0)
		{
			if (year % 400 != 0)
				february = 28;
		}
	}
	int daysPerMonths[] = {31, february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysPerMonths[month - 1])
	{
		std::cout << "Error: this day does not exist." << std::endl;
		return 1;
	}
	return 0;
}

int checkValue(std::string value, std::string line)
{
	for (int i = 0; value[i]; i++)
	{
		if (value[i] == '-')
			i++;
		if (!isdigit(value[i]) && value[i] != '.')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return 1;
		}
	}
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

int checkLine(std::string line, std::string & date, std::string & value)
{
	int i = 0;
	int year,month,day;
	for (;line[i] && line[i] != '|' ; i++);
	if (i >= static_cast<int>(line.size()))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return 1;
	}
	date = line.substr(0, i);

	//CHECK DATE
	getDate(date, year, month, day);
	if (checkDate(year, month, day) == 1)
		return 1;

	//CHECK VALUE
	while(line[i] && !isdigit(line[i]))
		i++;
	if (line[i - 1] == '-')
		i--;

	value = line.substr(i, line.size());
	if (value.empty())
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return 1;
	}
	return checkValue(value, line);
}

void BitcoinExchange::getMapValue(std::string date, std::string value)
{
	float a = strtof(value.c_str(), NULL);
	bool found = false;

	std::map<std::string, float>::key_compare comp = this->data.key_comp();
	std::map<std::string, float>::iterator it = this->data.begin();
	std::map<std::string, float>::iterator ite = this->data.end();
	for (; it != this->data.end(); ++it)
	{
		if (!comp(it->first, date))
		{
			found = true;
			--it;
			std::cout << date << "=> " << value << " => " << (*it).second * a << std::endl;
			break;
		}
	}
	if (!found)
		std::cout << date << "=> " << value << " => " << (*--ite).second * a << std::endl;
}

void BitcoinExchange::readInputFile(char* & file)
{
	std::ifstream outfile(file);
	if (!outfile.is_open())
	{
		throw FileNotOpenException();
	}

	std::string line, date, value;
	if (getline(outfile, line))
	{
		size_t found = line.find("date");
		if (found == std::string::npos)
		{
			if (checkLine(line, date, value) == 0)
				getMapValue(date, value);
		}
	}
	while(getline(outfile, line))
	{
		if (checkLine(line, date, value) == 0)
			getMapValue(date, value);
	}
}

void BitcoinExchange::printDataMap()
{
	std::map<std::string, float>::iterator it = this->data.begin();

	for (; it != this->data.end(); ++it)
		std::cout << it->first << " : " << it->second << std::endl;
}
