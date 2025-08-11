#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{

}

Ice::Ice(Ice const & copy)
{
	*this = copy;
}

Ice & Ice::operator=(Ice const & other)
{
	if (*this != other)
	{
		this->_type = other._type;
	}

	return *this;
}

Ice::~Ice()
{

}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone()
{
	return new Ice();
}