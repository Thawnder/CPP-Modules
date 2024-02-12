#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & base);
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=(PresidentialPardonForm const & base);

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;

};

#endif