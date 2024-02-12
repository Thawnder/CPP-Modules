#include "AForm.hpp"

AForm::AForm(): _signGrade(150), _execGrade(150), _isSigned(false) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, int const signGrade, int const execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
	std::cout << "Form string + int + int constructor called" << std::endl;
}

AForm::AForm(AForm const & base): _signGrade(base.getSignGrade()), _execGrade(base.getExecGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = base;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & base) {
	if (this != &base)
	{
		int *ptr1 = (int *) &this->_signGrade;
		int *ptr2 = (int *) &this->_execGrade;
		this->_isSigned = base.getState();
		*ptr1 = base.getSignGrade();
		*ptr2 = base.getExecGrade();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & output, AForm const & obj) {
	output << obj.getName() << " form, min. sign grade is " << obj.getSignGrade() << ", min. exec. grade is " << obj.getExecGrade() << std::endl << "Form status is " << obj.getState();
	return output;
}

std::string const AForm::getName() const {
	return this->_name;
}

void AForm::setName(std::string name) {
	std::string *ptr = (std::string *) &this->_name;
	*ptr = name;
}

bool AForm::getState() const {
	return this->_isSigned;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

int AForm::getExecGrade() const {
	return this->_execGrade;
}

void AForm::beSigned(Bureaucrat const & signer) {
	if (signer.getGrade() <= this->getSignGrade())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}