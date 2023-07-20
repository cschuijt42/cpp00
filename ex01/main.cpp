#include <iostream>
#include "PhoneBook.hpp"


void	add_contact(PhoneBook &phone_book)
{
	std::string	first, last, nick, phone, secret;

	std::cout << "First name:" << std::endl;
	std::cin >> first;

	std::cout << "Last name:" << std::endl;
	std::cin >> last;

	std::cout << "Nickname:" << std::endl;
	std::cin >> nick;

	std::cout << "Phone number:" << std::endl;
	std::cin >> phone;

	std::cout << "Darkest secret:" << std::endl;
	std::cin >> secret;

	phone_book.add(first, last, nick, phone, secret);
	std::cout << "Contact added successfully!" << std::endl;
}		

void	search_contacts(PhoneBook &phone_book)
{
	phone_book.overview();

	std::string	input;
	int			index;

	std::cout << "Please enter the index of the contact you want to view:" << std::endl;
	std::cin >> input;
	try
	{
		index = std::stoi(input);
	}
	catch(const std::exception & e)
	{
		std::cerr << "Could not convert to valid integer!" << std::endl;
		return;
	}

	try
	{
		phone_book.detail(index);
	}
	catch(const std::invalid_argument & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	PhoneBook	phone_book;
	std::string	command;
	while (true)
	{
		std::cout << "Please enter a command (ADD, SEARCH or EXIT):" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
			return 0;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			add_contact(phone_book);
		else if (command == "SEARCH")
			search_contacts(phone_book);
		else
			std::cout << "I don't know how to run that command, sorry.\n" << \
						 "(Valid commands are ADD, SEARCH and EXIT.)"     << std::endl;
	}

	return 0;
}
