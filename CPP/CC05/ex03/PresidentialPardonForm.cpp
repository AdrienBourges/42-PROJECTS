#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
	checkExecution(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

