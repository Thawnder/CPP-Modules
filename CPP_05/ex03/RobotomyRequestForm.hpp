#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & base);
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=(RobotomyRequestForm const & base);

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;

};

#endif