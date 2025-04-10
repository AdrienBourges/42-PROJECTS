#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
	checkExecution(executor);

	std::ofstream out((_target + "_shrubbery").c_str());
	out << "       🌳\n"
	    << "      🌳🌳\n"
	    << "     🌳🌳🌳\n"
	    << "      |||\n";
	out.close();
}

