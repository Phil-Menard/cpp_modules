#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("Someone")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm("shrubbery creation", 145, 137)
{
	*this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::printAsciiTreeInFile(std::ofstream & file) const
{
	file << "        &&& &&  & &&" << std::endl;
	file << "    && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "    &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << " &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	file << " &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "     &&     \\|||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "       , -=-~  .-^- _" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::checkBeforeExecution(executor);

		std::string name = this->_target + "_shrubbery";
		std::ofstream file(name.c_str());

		printAsciiTreeInFile(file);
		file.close();
	}
	catch(const std::exception& e)
	{
		throw;
	}
}
