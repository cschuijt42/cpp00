#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>


class	PhoneBook {
	public:
		PhoneBook();
		
		void	add(std::string first, std::string last, std::string nick, \
					std::string phone, std::string secret);
		void	overview(void);
		void	detail(int index);

	private:
		Contact	contacts[8];
		int	index;
};

#endif
