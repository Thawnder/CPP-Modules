#include "Contact.hpp"

Contact::Contact(){
	AddContact();
}

Contact::~Contact(){}

void Contact::AddContact(){
	while (!this->first_name[0])
	{
		std::cout << "Enter first name: ";
		std::cin >> this->first_name;
	}
	while (!this->last_name[0])
	{
		std::cout << "\nEnter last name: ";
		std::cin >> this->last_name;
	}
	while (!this->nickname[0])
	{
		std::cout << "\nEnter nickname: ";
		std::cin >> this->nickname;
	}
	while (!this->phone_nb[0])
	{
		std::cout << "\nEnter phone number: ";
		std::cin >> this->phone_nb;
		for (int i = 0; this->phone_nb[i]; i++)
		{
			if (!std::isdigit(this->phone_nb[i]))
			{
				std::cout << "Error: not a number.";
				this->phone_nb = "";
			}
		}
	}
	while (!this->dark_secret[0])
	{
		std::cout << "\nWrite your darkest secret: ";
		std::cin >> this->dark_secret;
	}
	std::cout << std::endl;
}