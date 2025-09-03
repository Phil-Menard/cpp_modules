#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "There should be one argument." << std::endl;
		return 1;
	}

	std::string arg = argv[1];
	PmergeMe merge(arg);
	merge.algo();

	return 0;
}
