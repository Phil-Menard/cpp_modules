#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("Someone")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("presidential pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) :
	AForm("Presidential Pardon", 25, 5)
{
	*this = copy;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::checkBeforeExecution(executor);
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}
