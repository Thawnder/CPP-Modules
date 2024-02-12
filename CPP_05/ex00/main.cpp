#include "Bureaucrat.hpp"

int main(void)
{
	try // Wrong grade in constructor
	{
		Bureaucrat timmy("timmy", 0);

		std::cout << timmy << std::endl;
		timmy.downGrade();
		std::cout << timmy << std::endl;
		timmy.upGrade();
		std::cout << timmy << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.ThrowError();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.ThrowError();
	}

	try // Grade too low after downgrade
	{
		Bureaucrat timmy("timmy", 150);

		std::cout << timmy << std::endl;
		timmy.downGrade();
		std::cout << timmy << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.ThrowError();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.ThrowError();
	}

	try // Grade too high after upgrade 
	{
		Bureaucrat timmy("timmy", 1);

		std::cout << timmy << std::endl;
		timmy.upGrade();
		std::cout << timmy << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.ThrowError();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.ThrowError();
	}

	try // Non-error case
	{
		Bureaucrat timmy("timmy", 1);

		std::cout << timmy << std::endl;
		timmy.downGrade();
		std::cout << timmy << std::endl;
		timmy.upGrade();
		std::cout << timmy << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.ThrowError();
		return 1;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.ThrowError();
		return 1;
	}
	return 0;
}