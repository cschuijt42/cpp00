#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

void	PhoneBook::add(std::string first, std::string last, \
					   std::string nick, std::string phone, \
					   std::string secret)
{
	try
	{
		contacts[index] = Contact(first, last, nick, phone, secret);

		index++;
		if (index >= 8)
			index = 0;
	}
	catch(const std::invalid_argument & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static std::string fit_to_table(std::string str)
{
	std::string	new_string;

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
	std::cout << "-----------------------------------------------------\n" <<
				 "|      Index | First name |  Last name |   Nickname |\n" <<
				 "-----------------------------------------------------"   << '\n';

	for (int i = 0; i < 8; i++)
	{
		std::cout << "| " << fit_to_table(std::to_string(i))          << " | " <<
							 fit_to_table(contacts[i].getFirstName()) << " | " <<
							 fit_to_table(contacts[i].getLastName())  << " | " <<
							 fit_to_table(contacts[i].getNickname())  << " |"  << '\n';
	}

	std::cout << "-----------------------------------------------------" << std::endl;
}

void	PhoneBook::detail(int index)
{
	if (index < 0 || index > 7)
		throw std::invalid_argument("Index must be between 0 and 7!");
	
	contacts[index].print_info();
}
