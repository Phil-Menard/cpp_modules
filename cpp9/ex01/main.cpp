#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "TThere should be one argument : the mathematical expression." << std::endl;
		return 1;
	}

	RPN rpn;
	std::string arg = argv[1];
	if (rpn.parseExpression(arg) == 1)
		return 1;
	rpn.calculExpression(arg);
	return 0;
}