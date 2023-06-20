#include <iostream>
#include "PhoneBook.hpp"

using	std::string, std::cin, std::cout, std::cerr, \
		std::endl, std::getline, std::stoi;


void	add_contact(PhoneBook *phone_book)
{
	string	first, last, nick, phone, secret;

	cout << "First name:" << endl;
	getline(cin, first);
	cout << "Last name:" << endl;
	getline(cin, last);
	cout << "Nickname:" << endl;
	getline(cin, nick);
	cout << "Phone number:" << endl;
	getline(cin, phone);
	cout << "Darkest secret:" << endl;
	getline(cin, secret);

	if ((*phone_book).add(first, last, nick, phone, secret))
		cout << "Contact added successfully!" << endl;
	else
		cout << "Contact could not be added. Did you leave a field empty?" << endl;
}		

void	search_contacts(PhoneBook *phone_book)
{
	(*phone_book).overview();

	string	input;
	int		index;

	cout << "Please enter the index of the contact you want to view:" << endl;
	getline(cin, input);
	try
	{
		index = stoi(input);
		if (!(*phone_book).detail(index))
		{
			cerr << "Could not look up that contact. Is the index valid?" << endl;
		}
	}
	catch (std::invalid_argument & e)
	{
		cerr << "Could not convert input to an integer." << endl;
	}
	catch (std::out_of_range & e)
	{
		cerr << "Input is out of valid integer range." << endl;
	}
}

int	main()
{
	PhoneBook	phone_book;

	phone_book.add("Hallooooooooooo", "hoi", "doei", "123", "xd");
	phone_book.add("doei", "dag", "xdxdxdxdxd", "123", "xdxdxdxdxd");

	string	command;
	while (true)
	{
		cout << "Please enter a command (ADD, SEARCH or EXIT):" << endl;
		getline(cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			add_contact(&phone_book);
		else if (command == "SEARCH")
			search_contacts(&phone_book);
		else
			cout << "I don't know how to run that command, sorry.\n" << \
					"(Valid commands are ADD, SEARCH and EXIT.)"     << endl;
	}

	return 0;
}
