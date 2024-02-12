#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat timmy("timmy", 75);
	Form one("raise", 74, 5);
	Form two("termination", 75, 5);

	std::cout << one << std::endl;
	std::cout << two << std::endl;

	timmy.signForm(one);
	timmy.signForm(two);

	std::cout << one << std::endl;
	std::cout << two << std::endl;

	return 0;
}