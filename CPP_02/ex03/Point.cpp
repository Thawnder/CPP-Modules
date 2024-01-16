#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(float const a, float const b): _x(a), _y(b) {}

Point::Point(Fixed const a, Fixed const b): _x(a), _y(b) {}

Point::Point(Point const & point) : _x(point.getX()), _y(point.getY()) {}


Point::~Point(){}

Point & Point::operator=(Point const & point) {
	if (this != &point)
	{
		(Fixed) this->_x = point.getX();
		(Fixed) this->_y = point.getY();
	}
	return *this;
}

Fixed Point::getX(void) const {return this->_x;}
Fixed Point::getY(void) const {return this->_y;}

std::ostream& operator<<(std::ostream& output, Point const & val) {
	output << "(" << val.getX().toFloat() << ", " << val.getY().toFloat() << ")";
	return output;
}