#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>

class Contact
{
private:

public:
	Contact();
	~Contact();

	Contact(int i);
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_nb;
	std::string dark_secret;

	void AddContact();
	void PrintNames(Contact contact, int i);
	void PrintInfo(Contact contact);
};

#endif