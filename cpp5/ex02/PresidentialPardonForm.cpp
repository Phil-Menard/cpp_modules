#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", false, 25, 5), _target("Someone")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon", false, 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy)
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
{
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned())
	{
		if (this->getGradeToExec() >= executor.getGrade())
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw AForm::GradeToExecTooLowException();
	}
	else
		throw AForm::NotSignedBeforeExecException();
}
