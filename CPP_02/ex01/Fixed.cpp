#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_pt = 0;
}

Fixed::Fixed(Fixed const & point) {
	std::cout << "Copy constructor called" << std::endl;
	*this = point;
}

Fixed::Fixed(int const val) {
	std::cout << "Int constructor called" << std::endl;
	this->_pt = val << this->_exp;
}

Fixed::Fixed(float const val) {
	std::cout << "Float constructor called" << std::endl;
	this->_pt = roundf(val * (1 << this->_exp));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & point) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point)
		this->_pt = point.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_pt;
}

void Fixed::setRawBits(int const raw) {
	this->_pt = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_pt / (1 << this->_exp);
}

int Fixed::toInt(void) const {
	return this->_pt >> this->_exp;
}

std::ostream& operator<<(std::ostream& output, Fixed const & point) {
	output << point.toFloat();
	return output;
}