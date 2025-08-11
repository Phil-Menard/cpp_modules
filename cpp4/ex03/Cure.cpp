#include "Cure.hpp"

Cure::Cure()
{

}

Cure::Cure(Cure const & copy)
{
	*this = copy;
}

Cure & Cure::operator=(Cure const & other)
{
	if (*this != other)
	{
		this->_type = other._type;
	}

	return *this;
}

Cure::~Cure()
{

}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure* Cure::clone()
{
	return new Cure();
}