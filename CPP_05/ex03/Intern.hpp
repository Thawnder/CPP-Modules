#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		std::string _forms[3];
	public:
		Intern();
		Intern(Intern const & base);
		~Intern();

		Intern & operator=(Intern const & base);

		std::string getForm(int i) const;

		AForm* makeForm(std::string name, std::string target);
};

#endif