#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor called" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat string + int constructor called" << std::endl;

	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & base) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = base;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & base) {
	if (this != &base)
	{
		(std::string) this->_name = base.getName();
		this->_grade = base.getGrade();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & output, Bureaucrat const & obj) {
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return output;
}

std::string const Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::upGrade() {
	if (this->_grade != 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::downGrade() {
	if (this->_grade != 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}