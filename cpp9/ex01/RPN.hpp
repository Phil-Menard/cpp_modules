#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(RPN const & copy);
		RPN & operator=(RPN const & other);
		~RPN();

		int parseExpression(std::string str);
		void calculExpression(std::string str);
		void add();
		void substract();
		void multiply();
		void divide();

	private:
		std::stack<int> rpnstack;
};

#endif