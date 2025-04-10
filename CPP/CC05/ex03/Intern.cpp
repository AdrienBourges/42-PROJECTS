#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

static AForm* makeShrubbery(const std::string& target) 
{
	return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) 
{
	return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string& target) 
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[3])(const std::string&) = 
	{
		&makeShrubbery,
		&makeRobotomy,
		&makePardon
	};

	for (int i = 0; i < 3; i++) 
	{
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern couldn't find a form called \"" << formName << "\"" << std::endl;
	return NULL;
}

