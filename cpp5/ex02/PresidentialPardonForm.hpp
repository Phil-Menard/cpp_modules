#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & other);
		~PresidentialPardonForm();

		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif