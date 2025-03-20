#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;

	while(1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			phonebook.add_contact();
		}
		else if (command == "SEARCH")
		{
			phonebook.search_contact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting phonebook ! \n";
			break;
		}
		else 
			std::cout << "Invalid command ! \n";
	}
}


