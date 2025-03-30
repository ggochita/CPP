#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int 	_gradeToSign;
	const int 	_gradeToExec;

public:
	AForm();
	AForm(const std::string &name, const int gradeToSign, const int gradeToExec);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm&	operator=(const AForm &other);
	
	const std::string& 	getName(void) const;
	bool			  	getIsSigned(void) const;
	int 		getGradeToSign(void) const;
	int 		getGradeToExec(void) const;


	void	beSigned(const Bureaucrat& bob);
	virtual void	execute(const Bureaucrat& executer) const = 0;

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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif