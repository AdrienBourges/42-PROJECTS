#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm 
{
private:
	std::string _target;

public:
	RobotomyRequestForm(const std::string& target);
	void execute(const Bureaucrat& executor) const;
};

#endif

