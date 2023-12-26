#include "Phonebook.hpp"

int main(void)
{
	std::string cmd;
	Phonebook pb;
	std::cout << "Welcome back to your personal phonebook." << std::endl;
	while (1)
	{
		std::cout << "What would you like to do? (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, cmd);
		cmd.erase(0, cmd.find_first_not_of(" \t\v\f\r"));
        cmd.erase(cmd.find_last_not_of(" \t\v\r\f") + 1, cmd[cmd.length() - 1]);
		if (cmd == "ADD")
			pb.Add();
		else if (cmd == "SEARCH")
			pb.Search(pb);
		else if (cmd == "EXIT")
			break;
		else if (cmd.empty())
			continue;
		else
			std::cout << "Invalid command." << std::endl;
	}
}