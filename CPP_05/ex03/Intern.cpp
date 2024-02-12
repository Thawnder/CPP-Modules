#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;

	_forms[0] = "Presidential Pardon";
	_forms[1] = "Robotomy Request";
	_forms[2] = "Shrubbery Creation";
}

Intern::Intern(Intern const & base) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = base;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}


Intern & Intern::operator=(Intern const & base) {
	if (this != &base)
	{
		for (int i = 0; i < 3; i++)
			this->_forms[i] = base.getForm(i);
	}
	return *this;
}

std::string Intern::getForm(int i) const {
	return this->_forms[i];
}


AForm* Intern::makeForm(std::string name, std::string target) {

	int i;

	for (i = 0; i < 3; i++)
	{
		if (name == this->_forms[i])
			break;
	}

	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));

		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));

		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		
		default:
			std::cout << "Intern can't create this form: it doesn't exist." << std::endl;
			break;
	}
	return (NULL);
}
