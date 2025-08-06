#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const & copy)
{
	std::cout << "Copy WrongCat constructor called." << std::endl;
	*this = copy;
}

WrongCat & WrongCat::operator=(WrongCat const & other)
{
	std::cout << "Affectation WrongCat operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}
