#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int 	_gradeToSign;
	const int 	_gradeToExec;

public:
	Form();
	Form(const std::string &name, const int gradeToSign, const int gradeToExec);
	Form(const Form &copy);
	~Form();

	Form&	operator=(const Form &other);
	
	const std::string& 	getName(void) const;
	bool			  	getIsSigned(void) const;
	int 		getGradeToSign(void) const;
	int 		getGradeToExec(void) const;


	void	beSigned(const Bureaucrat& bob);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif