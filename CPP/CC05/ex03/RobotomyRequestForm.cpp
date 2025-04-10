#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
	std::srand(std::time(0));
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{
	checkExecution(executor);

	std::cout << "🔧 Drilling noises... ";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully.\n";
	else
		std::cout << "Robotomy failed for " << _target << ".\n";
}

