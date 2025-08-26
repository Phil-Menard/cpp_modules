#include "Span.hpp"

int main()
{
	//SPAN EMPTY
	try
	{
		Span a;
		a.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "------------------" << std::endl;

	//SPAN FROM SUBJECT
	try
	{
		Span a(5);
		a.addNumber(6);
		a.addNumber(3);
		a.addNumber(17);
		a.addNumber(9);
		a.addNumber(11);
		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------------" << std::endl;

	//USE RANGE OF ITERATORS
	try
	{
		std::vector<int>v;
		v.push_back(6);
		v.push_back(3);
		v.push_back(17);
		v.push_back(9);
		v.push_back(11);
		Span a(5);
		a.addNumberRange(v.begin(), v.end());
		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------------------" << std::endl;

	//MASSIVE SPAN WITH RANDOM NUMBERS
	try
	{
		Span a(15000);
		a.addRandomNumberRange(a.getBeginIterator(), a.getEndIterator());
		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}