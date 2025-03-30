#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default-form"), _isSigned(false),
				_gradeToSign(5), _gradeToExec(2)
{
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExec)
:	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy)
:	_name(copy._name),
	_isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign),
	_gradeToExec(copy._gradeToExec)
{
}

Form::~Form()
{
}

const std::string& Form::getName(void) const
{
	return (_name);
}

bool Form::getIsSigned(void) const
{
	return (_isSigned);
}

int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return (_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bob)
{
	if (bob.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->_isSigned)
		throw AlreadySignedException();
	this->_isSigned = true;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form  grade is too HIGH!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form  grade is too LOW!");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Form  is already SIGNED!");
}


std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << "Form-name: " << rhs.getName() << std::endl
	<< "Form-Signed?: " << rhs.getIsSigned() << std::endl
	<< "Form-To-Sign: " << rhs.getGradeToSign() << std::endl
	<< "Form-To-Exec: " << rhs.getGradeToExec() << std::endl;
	return os;
}