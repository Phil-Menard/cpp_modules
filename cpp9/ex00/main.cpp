#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "There should be one argument (file) in order to compare the database." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.retrieveDataFile();
		btc.readInputFile(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
