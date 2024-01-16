#include "Point.hpp"

const Fixed area(Point const a, Point const b, Point const c) {
	Fixed area;

	area = ((b.getX() * a.getY() - a.getX() * b.getY())
			+ (c.getX() * b.getY() - b.getX() * c.getY())
			+ (a.getX() * c.getY() - c.getX() * a.getY())) / 2;
	
	if (area < 0)
		area = area * -1;
	return area;
}

bool onLine(Point const a, Point const b, Point const point) {
	return ((point.getX() - a.getX()) * (b.getY() - a.getY())
			- (point.getY() - a.getY()) * (b.getX() - a.getX())) == 0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed val = area(a, b, c);

	if (onLine(a, b, point) || onLine(b, c, point) || onLine(c, a, point))
		return false;
	else if (val != area(a, b, point) + area(b, c, point) + area(c, a, point))
		return false;
	return true;
}