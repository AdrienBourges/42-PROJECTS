#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	Bureaucrat john("John", 50);
	Bureaucrat alice("Alice", 1);

	Form taxForm("Tax Form", 45, 25);
	Form passport("Passport", 1, 1);

	std::cout << taxForm << std::endl;
	std::cout << passport << std::endl;

	john.signForm(taxForm);		// Should fail (50 > 45)
	alice.signForm(taxForm);	// Should work
	alice.signForm(passport);	// Should work
	john.signForm(passport);	// Should fail

	std::cout << taxForm << std::endl;
	std::cout << passport << std::endl;

	return 0;
}

