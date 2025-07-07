#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>

class File
{
public:
	File();
	~File();

	std::string		getBuffer();
	std::string		getFilename();
	std::string		getS1();
	std::string		getS2();

	void			setBuffer(std::ifstream& ifs);
	void			setFilename(char *str);
	void			setS1(char *str);
	void			setS2(char *str);
	void			modifyBuffer();

private:
	std::string		_filename;
	std::string		_buffer;
	std::string		_s1;
	std::string		_s2;
};

#endif