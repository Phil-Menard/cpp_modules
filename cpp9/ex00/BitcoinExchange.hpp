#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		BitcoinExchange & operator=(BitcoinExchange const & other);
		~BitcoinExchange();

		void retrieveDataFile();
		void displayBtc(char* & file);
		void printDataMap();

		class FileNotOpenException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		std::map<std::string, float> data;
};

#endif