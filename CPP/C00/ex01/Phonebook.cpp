#include "Phonebook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>

Phonebook::Phonebook() : next_index(0), contact_count(0) {}

void Phonebook::add_contact()
{
	contacts[next_index].set_info();
	next_index = (next_index + 1 ) % 8;
	if (contact_count < 8)
		contact_count++;
	std::cout << "Contact added succesfully !" << std::endl;
}

bool is_number(std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) 
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void Phonebook::search_contact()
{
	if (contact_count == 0)
	{
		std::cout << "Phonebook is empty ! " << std::endl;
		return ;
	}
   	std::cout << "|     index|first name| last name|  nickname|\n";
	for (int i = 0; i < contact_count; i++)
		contacts[i].display_summary(i);
	std::cout << "Enter Index: ";
	int index;
	std::string input;
	std::getline(std::cin, input);
	if (!is_number(input))
	{
		std::cout << "invalid index !\n";
			return ;
	}
	std::istringstream(input) >> index;
	if (index < 0 || index >= contact_count)
	{
		std::cout << "Invalid index !" << std::endl;
	}
	else 
	{
		contacts[index].display_all();
	}
}



