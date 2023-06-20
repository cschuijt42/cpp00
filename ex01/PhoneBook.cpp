#include <iostream>
#include <string>
#include "PhoneBook.hpp"

using std::string, std::cout, std::endl, std::to_string;

PhoneBook::PhoneBook()
{
	index = 0;
}

bool	PhoneBook::add(string first, string last, string nick, \
						string phone, string secret)
{
	if (!first.length() || !last.length() || !nick.length() || \
		!phone.length() || !secret.length())
		return false;
	
	Contact	new_contact;

	new_contact.first_name 		= first;
	new_contact.last_name 		= last;
	new_contact.nickname 		= nick;
	new_contact.phone_number 	= phone;
	new_contact.darkest_secret 	= secret;
	
	contacts[index] = new_contact;

	index++;
	if (index >= 8)
		index = 0;
	return true;
}

static string fit_to_table(string str)
{
	string	new_string;

	if (str.length() == 10)
		return str;
	else if (str.length() < 10)
	{
		for (int i = str.length(); i < 10; i++)
			new_string.append(" ");
		new_string.append(str);
	}
	else
	{
		new_string = str.substr(0, 9);
		new_string.append(".");
	}

	return new_string;
}

void	PhoneBook::overview()
{
	cout << "-----------------------------------------------------\n" <<
			"|      Index | First name |  Last name |   Nickname |\n" <<
			"-----------------------------------------------------" <<endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "| " << fit_to_table(to_string(i))           << " | " <<
						fit_to_table(contacts[i].first_name) << " | " <<
						fit_to_table(contacts[i].last_name)  << " | " <<
						fit_to_table(contacts[i].nickname)   << " |"  << endl;
	}
	cout << "-----------------------------------------------------" << endl;
}

bool	PhoneBook::detail(int index)
{
	if (index < 0 || index > 7)
		return false;
	cout << "First name: " << contacts[index].first_name     << "\n" <<
			"Last name:  " << contacts[index].last_name      << "\n" <<
			"Nickname:   " << contacts[index].nickname       << "\n" <<
			"Phone:      " << contacts[index].phone_number   << "\n" <<
			"Secret:     " << contacts[index].darkest_secret << endl;
	return true;
}
