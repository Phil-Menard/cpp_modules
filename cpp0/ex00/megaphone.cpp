#include <iostream>

int	main(int argc, char **argv)
{
	int		j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			j = -1;
			while (arg[++j])
				arg[j] = toupper(arg[j]);
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return (0);
}
