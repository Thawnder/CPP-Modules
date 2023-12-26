#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	Contact list[8];
	void Phonebook::Add();
	void Phonebook::Search();
	void Phonebook::Exit();
public:
	Phonebook();
	~Phonebook();
};

Phonebook::Phonebook(){}

Phonebook::~Phonebook(){}


#endif