#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() 
{
	Intern someIntern;
	AForm* shrub = someIntern.makeForm("shrubbery creation", "home");
	AForm* robo = someIntern.makeForm("robotomy request", "Bender");
	AForm* pardon = someIntern.makeForm("presidential pardon", "Ford");
	AForm* unknown = someIntern.makeForm("crazy form", "nobody");

	Bureaucrat boss("Alice", 1);

	if (shrub) 
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}
	if (robo) 
	{
		boss.signForm(*robo);
		boss.executeForm(*robo);
		delete robo;
	}
	if (pardon) 
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}

	delete unknown;

	return 0;
}

