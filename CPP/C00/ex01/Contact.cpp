#include "Contact.hpp"
#include "Phonebook.hpp"

std::string prompt_nonempty(const std::string &prompt) 
{
	std::string input;

	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "This field can't be empty. Please enter again.\n";
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
	}
    return input;
}

void Contact::set_info() // va permettre de remplir les infos de la classe contact
{
    first_name = prompt_nonempty("First Name");
    last_name = prompt_nonempty("Last Name");
    nickname = prompt_nonempty("Nickname");
    phone_number = prompt_nonempty("Phone Number");
    darkest_secret = prompt_nonempty("Darkest Secret");
}

void Contact::display_all() // permet de print toutes les infos d'un contact
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9) + ".";
	}
	return str;
}

void Contact::display_summary(int index)
{
	std::cout << "|"
			  << std::setw(10) << index << "|"
			  << std::setw(10) << truncate(first_name) << "|"
			  << std::setw(10) << truncate(last_name) << "|"
			  << std::setw(10) << truncate(nickname) << "|"
			  << "\n";
}
					

	
