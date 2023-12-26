#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>

class Contact
{
private:

public:
	Contact();
	~Contact();
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_nb;
	std::string dark_secret;

	void Contact::AddContact();
};

#endif