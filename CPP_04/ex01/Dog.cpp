#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const & base) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = base;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & base) {
	if (this != &base)
	{
		this->_type = base.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*base.getBrain());
	}
	return *this;
}

void Dog::setIdeas(std::string str) {
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, str);
}

Brain *Dog::getBrain() const {
	return this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Woof. Graou~" << std::endl;
}
