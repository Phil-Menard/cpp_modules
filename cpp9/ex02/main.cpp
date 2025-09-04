#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "There should be one argument." << std::endl;
		return 1;
	}

	std::string arg = argv[1];
	PmergeMe merge;
	merge.algo(arg);
	return 0;
}

//`shuf -i 1-1000 -n 3000 | tr "\n" " " `