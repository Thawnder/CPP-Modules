# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request", 72, 45) {
	std::cout << "RobotomyRequestForm string constructor called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & base): AForm(base) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = base;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & base) {
	if (this != &base)
		(std::string) this->_target = base.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getState() == false)
		throw NotSignedException();

	srand(time(NULL));

	int r = rand() % 2;

	std::cout << "*drilling noises*" << std::endl;
	if (r == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else if (r == 1)
		std::cout << this->_target << "'s robotomy has failed." << std::endl;
}