#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	int 		_grade;  // 1 is highest and 150 is lowest

public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& other);
	
	const std::string& getName() const;
	int getGrade() const;

	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(AForm& form) const;
	void	executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif