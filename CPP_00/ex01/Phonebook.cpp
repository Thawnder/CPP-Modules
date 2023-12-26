#include "Phonebook.hpp"

void Phonebook::Add()
{
	int	i;
	
	for (i = 0; list[i].first_name[0]; i++);
	if (i == 7)
		delete &list[i];
	for (i; i > 0; i--)
		list[i] = list[i - 1];
	list[0] = Contact();
}

void Phonebook::Search()
{

}

void Phonebook::Exit()
{

}