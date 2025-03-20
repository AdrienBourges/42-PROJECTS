#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
	private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string nickname;
	std::string darkest_secret;

	public:
	void set_info();
	void display_all();
	void display_summary(int index);
};
#endif
