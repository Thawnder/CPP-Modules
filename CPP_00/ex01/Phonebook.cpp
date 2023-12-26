#include "Phonebook.hpp"

Phonebook::Phonebook(void){}

Phonebook::~Phonebook(void){}

void Phonebook::Add()
{
	int	i;
	std::string confirm;
	
	for (i = 0; i < 8 && list[i].first_name[0]; i++);
	if (i == 8)
	{
		std::cout << "Warning. Maximum number of contacts reached." << std::endl << "Proceeding with this command with erase the oldest contact." << std::endl << "Do you want to proceed?" << std::endl;
		while (1)
		{
			std::getline(std::cin, confirm);
			confirm.erase(0, confirm.find_first_not_of(" \t\v\f\r"));
        	confirm.erase(confirm.find_last_not_of(" \t\v\r\f") + 1, confirm[confirm.length() - 1]);
			if (confirm == "Y" || confirm == "Yes" || confirm == "y" || confirm == "yes")
			{
				break;
				i--;
			}
			else if (confirm == "N" || confirm == "No" || confirm == "n" || confirm == "no")
				return ;
			else
				std::cout << "I don't understand. Do you want to proceed ?" << std::endl << "(Y/N/Yes/No) (Uppercase not required)" << std::endl;
		}
	}
	for (i; i > 0; i--)
		list[i] = list[i - 1];
	list[0] = Contact(1);
}

void Phonebook::Search(Phonebook pb)
{
	int i;
    int max;
    std::string index;

    i = 0;
    if (pb.list[0].first_name.empty())
    {
        std::cout << "There is nothing to search for, your phonebook is empty." << std::endl;
        return ;
    }
	std::cout << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    while (i < 8)
    {
        if (pb.list[i].first_name.empty())
            break ;
        std::cout << "|" << std::setw(10) << i << "|";
        list[i].PrintNames(list[i], 1);
        std::cout << "|";
        list[i].PrintNames(list[i], 2);
        std::cout << "|";
        list[i].PrintNames(list[i], 3);
        std::cout << "|\n";
        std::cout << "|-------------------------------------------|" << std::endl;
        i++;
    }
	max = i - 1;
	while (1)
    {
        std::cout << "Which contact's informations do you want me to show you ?" << std::endl << "Please enter a contact index, or leave empty to return." << std::endl;
        getline(std::cin, index);
        index.erase(0, index.find_first_not_of(" \t\v\f\r"));
        index.erase(index.find_last_not_of(" \t\v\r\f") + 1, index[index.length() - 1]);
        if (index.empty())
            break ;
        if (48 <= index[0] && index[0] <= 48 + max)
            i = (int)index[0] - 48;
        else
        {
            std::cout << "Invalid contact index." << std::endl;
            continue;
        }
        pb.list[i].PrintInfo(pb.list[i]);
        break ;
    }
}