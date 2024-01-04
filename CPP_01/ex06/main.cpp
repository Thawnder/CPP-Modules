#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl bot = Harl();
		bot.complain(argv[1]);
	}
	else
		std::cerr << "Invalid number of arguments." << std::endl;
	return (0);
}