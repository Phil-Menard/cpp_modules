#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <limits>
#include <math.h>
#include <iomanip>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const & copy)
{
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

bool isInt(std::string const str)
{
	int i = 0;
	if (str.size() == 1 && std::isdigit(str[0]))
		return true;
	if (str == "2147483648")
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (size_t j = i; j < str.size(); j++)
	{
		if (!std::isdigit(str[j]))
			return false;
	}
	int a = atoi(str.c_str());
	unsigned int b = abs(a);
	int index = str.size() - 1;
	while (index >= i && b > 0)
	{
		if (str[index] - '0' != b % 10)
			return false;
		b /= 10;
		index--;
	}
	if (index >= i || b > 0)
		return false;
	if (a > std::numeric_limits<int>::max() || a < std::numeric_limits<int>::min())
		return false;
	return true;
}

int countDigitsAfterComma(std::string const str)
{
	int count = 0;
	int i = str.size() - 1;
	while(str[i] == '0')
		i--;
	while (str[i] != '.')
	{
		count++;
		i--;
	}
	if (count == 0)
		return 1;
	return count;
}

bool isFloat(std::string const str)
{
	int i = 0;
	if (str[str.size()-1] != 'f')
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	int counter_dot = 0;
	for (size_t j = i; j < str.size() - 1; j++)
	{
		if (!std::isdigit(str[j]))
		{
			if (str[j] == '.')
				counter_dot++;
			else
				return false;
		}
	}
	if (counter_dot == 0 || counter_dot > 1)
		return false;
	float a = 0.0f, index_dot;
	while (str[i] != 'f')
	{
		if (str[i] == '.')
			index_dot = pow(10, str.size() - 2 - i);
		else
			a = (a * 10.0) + str[i] - '0';
		i++;
	}
	a /= index_dot;
	if (str[0] == '-')
		a *= -1;
	int precision = countDigitsAfterComma(str);
	std::cout << std::fixed << std::setprecision(precision) << a << "f" << std::endl;
	if (a > std::numeric_limits<float>::max() || a < std::numeric_limits<float>::min())
		return false;
	return true;
}

bool isDouble(std::string const str)
{
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	int counter_dot = 0;
	for (size_t j = i; j < str.size() - 1; j++)
	{
		if (!std::isdigit(str[j]))
		{
			if (str[j] == '.')
				counter_dot++;
			else
				return false;
		}
	}
	if (counter_dot == 0 || counter_dot > 1)
		return false;
	double a = 0.0, index_dot;
	while (str[i])
	{
		if (str[i] == '.')
			index_dot = pow(10, str.size() - 1 - i);
		else
			a = (a * 10.0) + str[i] - '0';
		i++;
	}
	a /= index_dot;
	if (str[0] == '-')
		a *= -1;
	int precision = countDigitsAfterComma(str);
	std::cout << std::fixed << std::setprecision(precision) << a << std::endl;
	if (a > std::numeric_limits<double>::max() || a < std::numeric_limits<double>::min())
		return false;
	return true;
}

void ScalarConverter::convert(std::string const str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		std::cout << "CHAR" << std::endl;
	else if (isInt(str))
		std::cout << "INT" << std::endl;
	else if (isFloat(str))
		std::cout << "FLOAT" << std::endl;
	else if (isDouble(str))
		std::cout << "DOUBLE" << std::endl;
	else
		std::cout << "The type conversion is impossible." << std::endl;
}
