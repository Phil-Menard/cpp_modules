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
	if (str[i] == 'f')
		i--;
	while(str[i] && str[i] == '0')
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

bool isFloat(std::string const str, float & a)
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
	float index_dot;
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
	if (a > std::numeric_limits<float>::max() || a < std::numeric_limits<float>::min())
		return false;
	return true;
}

bool isDouble(std::string const str, double & a)
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
	double index_dot;
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
	if (a > std::numeric_limits<double>::max() || a < std::numeric_limits<double>::min())
		return false;
	return true;
}

void convertFromChar(std::string const str)
{
	std::cout << "char: ";
	if ((str[0] >= 32 && str[0] <= 126) || (str[0] >= 9 && str[0] <= 13))
		std::cout << "'" << str[0] << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
}

void convertFromInt(std::string const str)
{
	int a = atoi(str.c_str());

	std::cout << "char: ";
	if ((a >= 32 && a <= 126) || (a >= 9 && a <= 13))
		std::cout << "'" << static_cast<char>(a) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << a << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a) << std::endl;
}

void convertFromFloat(std::string const str, float a, bool pl)
{
	int precision = 1;

	if (pl)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str[0] == '+')
		{
			std::cout << "float: " << std::fixed << std::setprecision(precision) << "+" << a << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(precision) << "+" << static_cast<double>(a) << std::endl;
		}
		else
		{
			std::cout << "float: " << std::fixed << std::setprecision(precision) << a << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(a) << std::endl;
		}
	}
	else
	{
		precision = countDigitsAfterComma(str);
		std::cout << "char: ";
		if ((a >= 32 && a <= 126) || (a >= 9 && a <= 13))
			std::cout << "'" << static_cast<char>(a) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(a) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << a << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(a) << std::endl;
	}
}

void convertFromDouble(std::string const str, double a, bool pl)
{
	int precision = 1;
	if (pl)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str[0] == '+')
		{
			std::cout << "float: " << std::fixed << std::setprecision(precision) << "+" << static_cast<float>(a) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(precision) << "+" << a << std::endl;
		}
		else
		{
			std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(a) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(precision) << a << std::endl;
		}
	}
	else
	{
		precision = countDigitsAfterComma(str);
		std::cout << "char: ";
		if ((a >= 32 && a <= 126) || (a >= 9 && a <= 13))
			std::cout << "'" << static_cast<char>(a) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(a) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(a) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision) << a << std::endl;
	}
}

bool isPseudoLiteral(std::string const str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		float a = strtof(str.c_str(), NULL);
		convertFromFloat(str, a, true);
		return true;
	}
	else if (str == "-inf" || str == "+inf" || str == "nan")
	{
		double d = strtod(str.c_str(), NULL);
		convertFromDouble(str, d, true);
		return true;
	}
	else
		return false;
}

void ScalarConverter::convert(std::string const str)
{
	float a = 0;
	double d = 0;

	if (str.size() == 1 && !std::isdigit(str[0]))
		convertFromChar(str);
	else if (isInt(str))
		convertFromInt(str);
	else if (isFloat(str, a))
		convertFromFloat(str, a, false);
	else if (isDouble(str, d))
		convertFromDouble(str, d, false);
	else
	{
		if (!isPseudoLiteral(str))
			std::cout << "The type conversion is impossible." << std::endl;
	}
}
