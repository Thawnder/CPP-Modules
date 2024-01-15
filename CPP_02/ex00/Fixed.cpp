#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_pt = 0;
}

Fixed::Fixed(Fixed const & point) {
	std::cout << "Copy constructor called" << std::endl;
	*this = point;
}

Fixed const & Fixed::operator=(Fixed const & point) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point)
		this->_pt = point.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_pt;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_pt = raw;
}