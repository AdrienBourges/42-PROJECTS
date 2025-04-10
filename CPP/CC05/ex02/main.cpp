#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	Bureaucrat alice("Alice", 1);
	Bureaucrat bob("Bob", 140);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Ford Prefect");

	alice.signForm(shrub);
	alice.signForm(robo);
	alice.signForm(pardon);

	alice.executeForm(shrub);
	alice.executeForm(robo);
	alice.executeForm(pardon);

	std::cout << "\nTrying with Bob:\n";
	bob.signForm(shrub);
	bob.executeForm(shrub);

	return 0;
}

