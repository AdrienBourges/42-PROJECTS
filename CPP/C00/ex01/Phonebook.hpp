#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class Phonebook {
	private:
	Contact contacts[8];
	int next_index;
	int contact_count;

	public:
		Phonebook(); // Contructor needed car on a besoin d'initiatliser des valeurs
		void add_contact();
		void search_contact();
};

#endif
	
