#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(float const a, float const b);
		Point(Fixed const a, Fixed const b);
		Point(Point const & point);
		~Point();

		Point & operator=(Point const & point);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

std::ostream& operator<<(std::ostream& output, Point const & point);

#endif