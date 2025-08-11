#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(AMateria const & copy)
{
	*this = copy;
}

AMateria & AMateria::operator=(AMateria const & other)
{
	if (*this != other)
	{
		this->_type = other.type;
	}

	return *this;
}

AMateria::~AMateria()
{

}

void AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
