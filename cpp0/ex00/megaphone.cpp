#include <iostream>

int	main(int argc, char **argv)
{
	char	letter;
	int		j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			j = -1;
			while (argv[i][++j])
			{
				letter = toupper(argv[i][j]);
				std::cout << letter;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
