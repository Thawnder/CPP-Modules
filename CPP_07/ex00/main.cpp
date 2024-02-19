#include "template.hpp"
#include <iostream>
#include <string>

int main(void)
{
	int a = 42;
	int b = 24;

	std::string c = "miguel";
	std::string d = "thomas";

	std::cout << "le meilleur c'est " << ::max(c, d) << std::endl;

	std::cout << "max: " << ::max(a, b) << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	::swap(a, b);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}