#include <iostream>
#include "File.hpp"

File::File()
{

}

File::~File()
{

}

std::string	File::getBuffer()
{
	return this->_buffer;
}

std::string	File::getFilename()
{
	return this->_filename;
}

std::string	File::getS1()
{
	return this->_s1;
}

std::string	File::getS2()
{
	return this->_s2;
}

void	File::setBuffer(std::ifstream& ifs)
{
	char	c;

	while (ifs.get(c))
		this->_buffer += c;
}

void	File::setFilename(char *str)
{
	this->_filename = str;
	this->_filename += ".replace";
}

void	File::setS1(char *str)
{
	this->_s1 = str;
}

void	File::setS2(char *str)
{
	this->_s2 = str;
}

void	File::modifyBuffer()
{
	for (std::size_t i = 0; i < this->_buffer.length(); i++)
	{
		if (this->_s1 != "" && this->_buffer.compare(i, this->_s1.length(), this->_s1) == 0)
		{
			this->_buffer.erase(i, this->_s1.length());
			this->_buffer.insert(i, this->_s2);
		}
	}
}
