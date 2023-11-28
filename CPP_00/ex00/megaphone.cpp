#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>

int	main(int argc, char **argv)
{
	std::locale loc;

	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
			for (int j = 0; argv[i][j]; j++)
				std::cout << std::toupper(argv[i][j], loc);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}