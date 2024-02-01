#include "Fixed.hpp"

Fixed::Fixed() {
	this->_pt = 0;
}

Fixed::Fixed(Fixed const & point) {
	*this = point;
}

Fixed::Fixed(int const val) {
	this->_pt = val << this->_exp;
}

Fixed::Fixed(float const val) {
	this->_pt = roundf(val * (1 << this->_exp));
}

Fixed::~Fixed() {}

Fixed & Fixed::operator=(Fixed const & point) {
	if (this != &point)
		this->_pt = point.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const & val) const {
	return (Fixed(this->toFloat() + val.toFloat()));
}

Fixed Fixed::operator-(Fixed const & val) const {
	return (Fixed(this->toFloat() - val.toFloat()));
}

Fixed Fixed::operator*(Fixed const & val) const {
	return (Fixed(this->toFloat() * val.toFloat()));
}

Fixed Fixed::operator/(Fixed const & val) const {
	return (Fixed(this->toFloat() / val.toFloat()));
}

Fixed & Fixed::operator++() {
	this->_pt++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_pt++;
	return tmp;
}

Fixed & Fixed::operator--() {
	this->_pt--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_pt--;
	return tmp;
}

bool Fixed::operator<(Fixed const & val) const {
	if (this->_pt < val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(Fixed const & val) const {
	if (this->_pt > val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const & val) const {
	if (this->_pt <= val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const & val) const {
	if (this->_pt >= val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const & val) const {
	if (this->_pt == val.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const & val) const {
	if (this->_pt != val.getRawBits())
		return true;
	return false;
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
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

std::ostream& operator<<(std::ostream& output, Fixed const & val) {
	output << val.toFloat();
	return output;
}