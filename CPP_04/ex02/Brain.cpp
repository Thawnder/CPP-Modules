#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & base) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = base;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const & base) {
	if (this != &base)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = base.getIdea(i);
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea) {
	this->_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
	return _ideas[i];
}