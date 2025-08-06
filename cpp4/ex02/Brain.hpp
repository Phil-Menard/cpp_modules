#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		// Brain(std::string *ideas);
		Brain(Brain const & copy);
		Brain & operator=(Brain const & other);
		~Brain();

	private:
		std::string ideas[100];
};

#endif