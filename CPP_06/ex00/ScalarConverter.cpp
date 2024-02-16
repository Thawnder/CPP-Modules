#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & base) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = base;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & base) {
	(void) base;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

int ScalarConverter::isInt(std::string src)
{
	for (int i = 0; (size_t)i < src.length(); i++)
	{
		if (!std::isdigit(src[i]))
		{
			if (i == 0 && src[i] == '-')
				continue;
			return 0;
		}
	}
	return 1;
}

int ScalarConverter::isFloat(std::string src)
{
	int checkdot = (int) src.find(".");
	int checkf = (int) src.find("f");

	if (checkdot == -1 || (size_t) checkf != src.length() - 1)
		return 0;
	for (int i = 0; (size_t) i < src.length(); i++)
	{
		if (i == 0 && src[i] == '-')
			continue;
		if (i != checkdot && i != checkf && !std::isdigit(src[i]))
			return 0;
	}
	return 1;
}

int ScalarConverter::isDouble(std::string src)
{
	int checkdot = src.find(".");

	if (checkdot == -1)
		return 0;
	for (int i = 0; (size_t) i < src.length(); i++)
	{
		if (i == 0 && src[i] == '-')
			continue;
		if (i != checkdot && !std::isdigit(src[i]))
			return 0;
	}
	return 1;
}

void ScalarConverter::convert(std::string src) {

	const std::string pseudo_values[6] = {"-inff", "nanf", "+inff", "-inf", "nan", "+inf"};

	if (src.length() == 1 && (src[0] < 32 || src[0] > 126))
		return (std::cout << "Non displayable character not accepted as input." << std::endl, (void)0);

	if (src.length() == 1 && !std::isdigit(src[0])) // is char
	{
		std::cout << "Char: " << src << std::endl;
		std::cout << "Int: " << static_cast<int>(src[0]) << std::endl;
		std::cout << "Float: " << static_cast<float>(src[0]) << std::endl;
		std::cout << "Double: " << static_cast<double>(src[0]) << std::endl;
	}
	else if (isInt(src))
	{
		int res = std::atoi(src.c_str());

		if (res >= 32 && res <= 126)
			std::cout << "Char: " << static_cast<char>(res) << std::endl;
		else
			std::cout << "Char: Non displayable" << std::endl; 
		std::cout << "Int: " << res << std::endl;
		std::cout << "Float: " << static_cast<float>(res) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(res) << ".0" << std::endl;
	}
	else if (isFloat(src))
	{
		float res = std::atof(src.c_str());

		if (static_cast<int>(res) >= 32 && static_cast<int>(res) <= 126)
			std::cout << "Char: " << static_cast<char>(res) << std::endl;
		else
			std::cout << "Char: Non displayable" << std::endl; 
		std::cout << "Int: " << static_cast<int>(res) << std::endl;
		std::cout << "Float: " << res << (res - static_cast<int>(res) == 0 ? ".0f" : "f") << std::endl;
		std::cout << "Double: " << static_cast<double>(res) << (res - static_cast<int>(res) == 0 ? ".0" : "") << std::endl;
	}
	else if (isDouble(src))
	{
		double res = std::atof(src.c_str());

		if (static_cast<int>(res) >= 32 && static_cast<int>(res) <= 126)
			std::cout << "Char: " << static_cast<char>(res) << std::endl;
		else
			std::cout << "Char: Non displayable" << std::endl; 
		std::cout << "Int: " << static_cast<int>(res) << std::endl;
		std::cout << "Float: " << static_cast<float>(res) << (res - static_cast<int>(res) == 0 ? ".0f" : "f") << std::endl;
		std::cout << "Double: " << res << (res - static_cast<int>(res) == 0 ? ".0" : "") << std::endl;
	}
	else
	{
		int	i;

		for (i = 0; (size_t) i < sizeof(pseudo_values)/sizeof(*pseudo_values); i++)
			if (src == pseudo_values[i])
				break;
		
		if (i < 6)
		{
			std::cout << "Char: Impossible" << std::endl;
			std::cout << "Int: Impossible" << std::endl;
			if (i < 3)
			{
				std::cout << "Float: " << pseudo_values[i] << std::endl;
				std::cout << "Double: " << pseudo_values[i + 3] << std::endl;
			}
			else
			{
				std::cout << "Float: " << pseudo_values[i - 3] << std::endl;
				std::cout << "Double: " << pseudo_values[i] << std::endl;
			}
		}
		else
			std::cout << "Error: not a valid literal." << std::endl;
	}
}