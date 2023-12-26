#include "Contact.hpp"

Contact::Contact(void){
}

Contact::Contact(int i)
{
	AddContact();
}

Contact::~Contact(void){}

void Contact::AddContact(){
	std::cout << std::endl;
	while (this->first_name.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, this->first_name);
	}
	while (this->last_name.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, this->last_name);
	}
	while (this->nickname.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, this->nickname);
	}
	while (this->phone_nb.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, this->phone_nb);
		for (int i = 0; this->phone_nb[i]; i++)
		{
			if (!std::isdigit(this->phone_nb[i]))
			{
				std::cout << "Error: not a number." << std::endl;
				this->phone_nb = "";
				break;
			}
		}
	}
	while (this->dark_secret.empty())
	{
		std::cout << "Write his/her darkest secret: ";
		std::getline(std::cin, this->dark_secret);
	}
	std::cout << std::endl;
}

void Contact::PrintNames(Contact contact, int i)
{
    if (i == 1)
    {
        if (contact.first_name.size() > 10)
            std::cout << std::string(contact.first_name.begin(), contact.first_name.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact.first_name;
    }
    if (i == 2)
    {
        if (contact.last_name.size() > 10)
            std::cout << std::string(contact.last_name.begin(), contact.last_name.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact.last_name;
    }
    if (i == 3)
    {
        if (contact.nickname.size() > 10)
            std::cout << std::string(contact.nickname.begin(), contact.nickname.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact.nickname;
    }
}

void    Contact::PrintInfo(Contact contact)
{
    std::cout << std::endl << "First name: " << contact.first_name << std::endl;
    std::cout << "Last name: " << contact.last_name << std::endl;
    std::cout << "Nickname: " << contact.nickname << std::endl;
    std::cout << "Phone number: " << contact.phone_nb << std::endl;
    std::cout << "Darkest secret: " << contact.dark_secret << std::endl << std::endl;
}