#include "Phonebook.hpp"

void Phonebook::Add()
{
	int	i;
	std::string confirm;
	
	for (i = 0; list[i].first_name[0]; i++);
	if (i == 7)
	{
		std::cout << "Warning. Maximum number of contacts reached. Proceeding with this command with erase the oldest contact. Do you want to proceed?" << std::endl;
		while (1)
		{
			std::getline(std::cin, confirm);
			confirm.erase(0, confirm.find_first_not_of(" \t\v\f\r"));
        	confirm.erase(confirm.find_last_not_of(" \t\v\r\f") + 1, confirm[confirm.length() - 1]);
			if (confirm == "Y" || confirm == "Yes" || confirm == "y" || confirm == "yes")
			{
				delete &list[i];
				break;
			}
			else if (confirm == "N" || confirm == "No" || confirm == "n" || confirm == "no")
				return ;
			else
				std::cout << "I don't understand. Do you want to proceed ? (Y/N/Yes/No) (Uppercase not required)" << std::endl;
		}
	}
	for (i; i > 0; i--)
		list[i] = list[i - 1];
	list[0] = Contact();
}

void Phonebook::Search()
{

}