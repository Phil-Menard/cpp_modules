#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "There should be a sequence of positive number as argument." << std::endl;
		return 1;
	}

	PmergeMe merge;
	merge.algo(argv);
	return 0;
}
