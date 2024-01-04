#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::_debug(void)
{
	std::cout << "This is a debug message sample. My role as an AI is to guide you however I can." << std::endl;
}

void Harl::_info(void)
{
	std::cout << "This is an info message sample. I can place different level of messages in the code, wherever you want me to. It can be personalized by you, me, or simply a default message." << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "This is a warning message sample. Whenever you encounter those, I can analyze test outputs and figure out how unwise it would be to ignore them, what consequences they would have on my system." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is an error message sample. In most cases I'll shut down immediately, but I will inform you about the cause before doing so. You'll be on your own." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->str[i])
		{
			(this->*lvl[i])();
			return ;
		}
	}
	std::cout << "Wrong command." << std::endl;
}