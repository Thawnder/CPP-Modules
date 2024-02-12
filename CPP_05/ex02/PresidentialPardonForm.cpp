# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5) {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", 25, 5) {
	std::cout << "PresidentialPardonForm string constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & base): AForm(base) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = base;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & base) {
	if (this != &base)
		(std::string) this->_target = base.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getState() == false)
		throw NotSignedException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}