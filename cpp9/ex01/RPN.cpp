#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN const & copy)
{
	*this = copy;
}

RPN & RPN::operator=(RPN const & other)
{
	if (this != &other)
	{
		this->rpnstack = other.rpnstack;
	}
	return *this;
}

RPN::~RPN()
{}

int RPN::parseExpression(std::string str)
{
	int number = 0;
	int oper = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*'
			&& str[i] != '/' && str[i] != ' ')
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		else
		{
			if (isdigit(str[i]))
				number++;
			else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
				oper++;
			if (str[i] != ' ' && str[i + 1] != ' ' && i+1 != str.size())
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
	}
	//check ratio numbers / operators
	if (oper != number - 1)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}

void RPN::calculExpression(std::string str)
{
	for (size_t i = 0; i < str.size(); i+=2)
	{
		if (isdigit(str[i]))
			this->rpnstack.push(str[i] - '0');
		else
		{
			if (this->rpnstack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			if (str[i] == '+')
				add();
			else if (str[i] == '-')
				substract();
			else if (str[i] == '*')
				multiply();
			else
				divide();
		}
	}
	if (this->rpnstack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << this->rpnstack.top() << std::endl;
}

void RPN::add()
{
	int x = this->rpnstack.top();
	this->rpnstack.pop();
	int y = this->rpnstack.top();
	this->rpnstack.pop();
	this->rpnstack.push(x + y);
}

void RPN::substract()
{
	int x = this->rpnstack.top();
	this->rpnstack.pop();
	int y = this->rpnstack.top();
	this->rpnstack.pop();
	this->rpnstack.push(y - x);
}

void RPN::multiply()
{
	int x = this->rpnstack.top();
	this->rpnstack.pop();
	int y = this->rpnstack.top();
	this->rpnstack.pop();
	this->rpnstack.push(x * y);
}

void RPN::divide()
{
	int x = this->rpnstack.top();
	this->rpnstack.pop();
	int y = this->rpnstack.top();
	this->rpnstack.pop();
	this->rpnstack.push(y / x);
}
