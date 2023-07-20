#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class	Contact {
	public:
		Contact(void);
		Contact(std::string first_name, std::string last_name, \
				std::string nickname, std::string phone_number, \
				std::string darkest_secret);
		
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);

		void print_info(void);

	private:
		std::string	first_name, last_name, nickname, \
					phone_number, darkest_secret;
};

#endif
