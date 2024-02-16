#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & base);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & base);

		std::string const getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();
		void signForm(AForm & form);

		void executeForm(AForm const & form);

		class GradeTooHighException{
			public:
			void ThrowError() {
				std::cout << "Error: grade too high" << std::endl;
			}
		};

		class GradeTooLowException {
			public:
			void ThrowError() {
				std::cout << "Error: grade too low" << std::endl;
			}
		};
};

std::ostream & operator<<(std::ostream & output, Bureaucrat const & obj);

#endif