#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		int const _signGrade;
		int const _execGrade;
		bool	_isSigned;

	public:
		AForm();
		AForm(std::string name, int const signGrade, int const execGrade);
		AForm(AForm const & base);
		virtual ~AForm();

		AForm & operator=(AForm const & base);

		std::string const getName() const;
		void setName(std::string name);
		bool getState() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		void beSigned(Bureaucrat const & signer);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException {
			public:
			void ThrowError() {
				std::cout << "Signer grade is too low." << std::endl;
			}
		};

		class NotSignedException {
			public:
			void ThrowError() {
				std::cout << "Form hasn't been signed." << std::endl;
			}
		};
};

std::ostream & operator<<(std::ostream & output, AForm const & obj);

#endif