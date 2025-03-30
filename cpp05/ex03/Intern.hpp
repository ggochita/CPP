#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	~Intern();

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& name, const std::string& target) const;
	AForm* creatShrubbery(const std::string& target) const;
	AForm* creatRobotomy(const std::string& target) const;
	AForm* creatPresidential(const std::string& target) const;
};

#endif