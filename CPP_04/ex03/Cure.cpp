#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	if (DEBUG)
		std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & base) {
	if (DEBUG)
		std::cout << "Cure copy constructor called" << std::endl;
	*this = base;
}

Cure::~Cure() {
	if (DEBUG)
		std::cout << "Cure destructor called" << std::endl;
}


Cure & Cure::operator=(Cure const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}