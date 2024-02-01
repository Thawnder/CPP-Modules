#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	if (DEBUG)
		std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & base): AMateria(base) {
	if (DEBUG)
		std::cout << "Ice copy constructor called" << std::endl;
	*this = base;
}

Ice::~Ice() {
	if (DEBUG)
		std::cout << "Ice destructor called" << std::endl;
}


Ice & Ice::operator=(Ice const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}