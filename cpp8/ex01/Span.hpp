#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(Span const & copy);
		Span & operator=(Span const & copy);
		~Span();

	void addNumber(int n);
	void addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void addRandomNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
	int shortestSpan();
	int longestSpan();

	std::vector<int>::iterator getBeginIterator();
	std::vector<int>::iterator getEndIterator();

	class ContainerFullException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class NoSpanPossibleException : public std::exception
	{
		virtual const char* what() const throw();
	};

	private:
		std::vector<int> _v;
		unsigned int _size;
		unsigned int _index;
};

#endif