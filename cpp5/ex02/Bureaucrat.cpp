#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(100)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	*this = copy;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::signForm(AForm & form) const
{
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " because his/her grade is too low." << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << "The form can not be executed because " << e.what() << std::endl;;
	}
}

void Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
