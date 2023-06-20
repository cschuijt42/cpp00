#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>

using std::string;

class	PhoneBook {
	public:
		PhoneBook();
		
		bool	add(string first, string last, string nick, \
						string phone, string secret);
		void	overview();
		bool	detail(int index);

	private:
		Contact	contacts[8];
		int	index;
};

#endif
