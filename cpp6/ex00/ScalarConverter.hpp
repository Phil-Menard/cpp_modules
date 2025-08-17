#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
		static void convert(std::string const str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter & operator=(ScalarConverter const & other);
		~ScalarConverter();
};

#endif