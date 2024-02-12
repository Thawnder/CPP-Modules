#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern timmy;
	Bureaucrat adolf("adolf", 1);

	AForm *one = timmy.makeForm("Presidential Pardon", "Kanye");

	if (one)
	{
		std::cout << *one << std::endl;

		adolf.executeForm(*one);
		adolf.signForm(*one);
		adolf.executeForm(*one);
		delete one;
	}

	AForm *two = timmy.makeForm("Diet Program", "Yo momma");
	
	if (two)
	{
		std::cout << two << std::endl;
		delete two;
	}

	return 0;
}