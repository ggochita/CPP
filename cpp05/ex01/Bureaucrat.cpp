#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Barry"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form& form) const
{
	try{
		form.beSigned(*this);
		std::cout	<< this->getName()
					<< " signed "
					<< form.getName()
					<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cout	<< this->getName()
					<< " couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
	}
}

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too HIGH!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too LOW!");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", Bureaucrat of grade "
		<< rhs.getGrade() << std::endl;
	return os;
}