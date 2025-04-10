#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(const std::string& target);
	void execute(const Bureaucrat& executor) const;
};

#endif

