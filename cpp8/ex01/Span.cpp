#include "Span.hpp"

Span::Span() : _v(), _size(0), _index(0)
{}

Span::Span(unsigned int n) : _v(n), _size(n), _index(0)
{}

Span::Span(Span const & copy)
{
	*this = copy;
}

Span & Span::operator=(Span const & other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_v = other._v;
	}
	return *this;
}

Span::~Span()
{

}

const char* Span::ContainerFullException::what() const throw()
{
	return "The container is already full.";
}

const char* Span::NoSpanPossibleException::what() const throw()
{
	return "At least two elements are needed to find out a span.";
}

void Span::addNumber(int n)
{
	if (this->_index < this->_size)
	{
		this->_v[this->_index] = n;
		this->_index++;
	}
	else
		throw ContainerFullException();
}

void Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	this->_index = 0;
	for (; begin != end; ++begin)
	{
		this->_v[this->_index] = *begin;
		this->_index++;
	}
}

void Span::addRandomNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	srand(time(NULL));
	for (; begin != end; ++begin)
	{
		int r = rand();
		*begin = r;
	}
	this->_index = this->_size;
}

int Span::shortestSpan()
{
	if (this->_index < 2)
		throw NoSpanPossibleException();
	else
	{
		sort(this->_v.begin(), this->_v.end());
		int a = this->_v[this->_index - 1];
		for (int i = this->_index - 1; i > 0; i--)
		{
			if (this->_v[i] - this->_v[i - 1] < a)
				a = this->_v[i] - this->_v[i - 1];
		}
		return a;
	}
}

int Span::longestSpan()
{
	if (this->_index < 2)
		throw NoSpanPossibleException();
	else
	{
		sort(this->_v.begin(), this->_v.end());
		return this->_v[this->_index - 1] - this->_v[0];
	}
}

std::vector<int>::iterator Span::getBeginIterator()
{
	return this->_v.begin();
}

std::vector<int>::iterator Span::getEndIterator()
{
	return this->_v.end();
}
