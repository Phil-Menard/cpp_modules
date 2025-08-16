#include "Form.hpp"

Form::Form() : _name("default") ,_isSigned(false), _gradeToSign(100), _gradeToExec(100)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->getGradeToSign() <= 0)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & copy) : _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	*this = copy;
}

Form & Form::operator=(Form const & other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	else if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade required to sign the form is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade required to sign the form is too low.";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "The form has already been signed.";
}

std::ostream & operator<<(std::ostream & out, Form const & form)
{
	out << "Form under name '" << form.getName() << "' is ";
	if (form.getIsSigned())
		out << "signed. A grade of " << form.getGradeToExec() << " is required to execute it.";
	else
	{
		out << "not signed. A grade of " << form.getGradeToSign() << " is required to sign it. ";
		out << "A grade of " << form.getGradeToExec() << " is required to execute it.";
	}
	return out;
}
