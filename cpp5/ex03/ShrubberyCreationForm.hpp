#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);
		~ShrubberyCreationForm();

		void printAsciiTreeInFile(std::ofstream & file) const;
		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif