#ifndef PRRSIDENTIALPARDONFORM_HPP
# define PRRSIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;
public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();

	void	execute(const Bureaucrat& executer) const;
	
};

#endif