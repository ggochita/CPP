#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (executer.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();

	std::ofstream	file((_target + "_shrubbery").c_str());
	if (!file)
		throw	std::runtime_error("Could not open file");

	file << "                                      .         ;   " << std::endl; 
	file << "      .              .              ;%     ;;       " << std::endl;
	file << "        ,           ,                :;%  %;        " << std::endl;
	file << "         :         ;                   :;%;'     ., " << std::endl; 
	file << ",.        %;     %;            ;        %;'    ,;   " << std::endl;
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'    " << std::endl;
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'     " << std::endl;
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'       " << std::endl;
	file << "     `%;.     ;%;     %;'         `;%%;.%;'         " << std::endl;
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'            " << std::endl;
	file << "         `:%;.  :;bd%;          %;@%;'              " << std::endl;
	file << "           `@%:.  :;%.         ;@@%;'               " << std::endl;
	file << "             `@%.  `;@%.      ;@@%;                 " << std::endl;
	file << "               `@%%. `@%%    ;@@%;                  " << std::endl;
	file << "                 ;@%. :@%%  %@@%;                   " << std::endl;
	file << "                   %@bd%%%bd%%:;                    " << std::endl;
	file << "                     #@%%%%%:;;                     " << std::endl;
	file << "                     %@@%%%::;                      " << std::endl;
	file << "                     %@@@%(o);  . '                 " << std::endl;
	file << "                     %@@@o%;:(.,'                   " << std::endl;
	file << "                 `.. %@@@o%::;                      " << std::endl;
	file << "                    `)@@@o%::;                      " << std::endl;
	file << "                     %@@(o)::;                      " << std::endl;
	file << "                    .%@@@@%::;                      " << std::endl;
	file << "                    ;%@@@@%::;.                     " << std::endl;
	file << "                   ;%@@@@%%:;;;.                    " << std::endl;
	file << "               ...;%@@@@@%%:;;;;,..                 " << std::endl;
	file.close();

	std::cout << _target << "_shrubbery created successfully!" << std::endl;
}