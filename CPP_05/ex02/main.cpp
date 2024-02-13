#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat timmy("timmy", 139);
	Bureaucrat elon("elon", 44);
	Bureaucrat adolf("adolf", 1);

	PresidentialPardonForm one("Kanye");
	RobotomyRequestForm two("Kentin");
	ShrubberyCreationForm tri("Kid");

	std::cout << one << std::endl;
	std::cout << two << std::endl;
	std::cout << tri << std::endl;


	timmy.signForm(two);
	timmy.executeForm(tri);
	elon.executeForm(tri);
	elon.signForm(tri);
	elon.executeForm(tri);
	elon.signForm(two);
	elon.signForm(one);
	adolf.executeForm(two);
	adolf.signForm(one);
	adolf.executeForm(one);

	std::cout << one << std::endl;
	std::cout << two << std::endl;
	std::cout << tri << std::endl;

	return 0;
}