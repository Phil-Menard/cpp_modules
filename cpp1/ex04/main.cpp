#include <iostream>
#include <fstream>
#include "File.hpp"

int	check_nb_args(int argc)
{
	if (argc < 4)
	{
		std::cout << "Not enough arguments. There should be 3 : [filename] [s1] [s2]" << std::endl;
		return 1;
	}
	else if (argc > 4)
	{
		std::cout << "Too much arguments. There should be 3 : [filename] [s1] [s2]" << std::endl;
		return 1;
	}
	else
		return 0;
}

int	main(int argc, char **argv)
{
	//verify args
	if (check_nb_args(argc) == 1)
		return 1;

	File file;
	std::ifstream ifs(argv[1]);

	//set args as strings
	file.setFilename(argv[1]);
	file.setS1(argv[2]);
	file.setS2(argv[3]);

	//check if file opened correctly
	if (!ifs.is_open())
	{
		std::cout << "Error opening the file." << std::endl;
		return 1;
	}

	//retrieve buffer letter by letter, then close file
	file.setBuffer(ifs);
	ifs.close();

	//modify buffer and send it into new file
	file.modifyBuffer();
	std::ofstream ofs(file.getFilename().c_str());
	ofs << file.getBuffer() << std::endl;

	return 0;
}
