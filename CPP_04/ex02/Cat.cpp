#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const & base) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = base;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat& Cat::operator=(Cat const & base) {
	if (this != &base)
	{
		this->_type = base.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*base.getBrain());
	}
	return *this;
}

void Cat::setIdeas(std::string str) {
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, str);
}

Brain *Cat::getBrain() const {
	return this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Meow. Nyan~" << std::endl;
}
