#include "AMateria.hpp"

AMateria::AMateria() {
	if (DEBUG)
		std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "";
}

AMateria::AMateria(std::string const & type) {
	if (DEBUG)
		std::cout << "AMateria string constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria const & base) {
	if (DEBUG)
		std::cout << "AMateria copy constructor called" << std::endl;
	*this = base;
}

AMateria::~AMateria() {
	if (DEBUG)
		std::cout << "AMateria destructor called" << std::endl;
}


AMateria & AMateria::operator=(AMateria const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}


std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "TF you doing bruh? Ain't nothing wrong with " << target.getName() << ", you're the wrong one !" << std::endl;
}