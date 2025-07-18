#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void	complain(std::string level);

private:
	void	debug();
	void	info();
	void	warning();
	void	error();

	struct levels
	{
		std::string	_level;
		void		(Harl::*func)();
	};
	
	static const levels arr[4];
};

#endif