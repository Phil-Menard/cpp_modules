#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_type = NULL;
}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	if (this->_type != NULL)
		std::cout << this->_name << " attacks with their " << this->_type->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->_type = &type;
}
