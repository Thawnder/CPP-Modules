#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		int const _signGrade;
		int const _execGrade;
		bool	_isSigned;

	public:
		Form();
		Form(std::string name, int const signGrade, int const execGrade);
		Form(Form const & base);
		~Form();

		Form & operator=(Form const & base);

		std::string const getName() const;
		void setName(std::string name);
		bool getState() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		void beSigned(Bureaucrat & signer);

		class GradeTooLowException {
			public:
			void ThrowError() {
				std::cout << "Signer grade is too low." << std::endl;
			}
		};
};

std::ostream & operator<<(std::ostream & output, Form const & obj);

#endif