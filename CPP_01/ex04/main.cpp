#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string text;
		char	tmp[1];
		char	buf[strlen(argv[1]) + 8];
		strcpy(buf, argv[1]);
		strcat(buf, ".replace");
		std::fstream src;
		std::fstream dest;

		src.open(argv[1], std::fstream::in);
		if (!src.is_open())
		{
			std::cerr << "src open: failed" << std::endl;
			return (-1);
		}
		while (src.read(tmp, 1) && tmp[0] != EOF)
			text += tmp;
		src.close();
		dest.open(buf, std::fstream::out);
		if (!dest.is_open())
		{
			std::cerr << "dest open: failed" << std::endl;
			return (-1);
		}
		for (std::string::iterator it = text.begin(); it != text.end(); it++)
		{
			if (*it != argv[2][0] || strncmp(&*it, argv[2], strlen(argv[2])))
				dest.write(&*it, 1);
			else if (!strncmp(&*it, argv[2], strlen(argv[2])))
			{
				it += strlen(argv[2]) - 1;
				dest.write(argv[3], strlen(argv[3]));
			}
		}
		dest.close();
	}
	else
		std::cerr << "Invalid arguments" << std::endl;
	return (0);
}