#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Format error. Expected format: ./convert <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}