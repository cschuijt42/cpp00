#include "Contact.hpp"
#include <iostream>


Contact::Contact(void) { }

Contact::Contact(std::string first, std::string last, \
				 std::string nick, std::string phone, \
				 std::string secret) {
	if (!first.length() || !last.length() || !nick.length() || \
		!phone.length() || !secret.length())
		throw std::invalid_argument("Empty fields are not allowed!");
	first_name     = first;
	last_name      = last;
	nickname       = nick;
	phone_number   = phone;
	darkest_secret = secret;
}

std::string Contact::getFirstName(void) {
	return first_name;
}

std::string Contact::getLastName(void) {
	return last_name;
}

std::string Contact::getNickname(void) {
	return nickname;
}

void	Contact::print_info(void)
{
	std::cout << "First name: " << first_name     << "\n" <<
				 "Last name:  " << last_name      << "\n" <<
				 "Nickname:   " << nickname       << "\n" <<
				 "Phone:      " << phone_number   << "\n" <<
				 "Secret:     " << darkest_secret << std::endl;
}
