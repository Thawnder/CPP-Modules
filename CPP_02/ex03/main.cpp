#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void) {

	Fixed x1(0);
	Fixed y1(0);	
	Fixed x2(5);
	Fixed y2(5);	
	Fixed x3(10);
	Fixed y3(0);
	Point p1(x1, y1);
	Point p2(x2, y2);
	Point p3(x3, y3);

	Point p(Fixed(5), Fixed(1));
	if (bsp(p1, p2, p3, p))
		std::cout << "Le point " << p << " fait partie du triangle." << std::endl;
	else
		std::cout << "Le point " << p << " ne fait pas partie du triangle." << std::endl;

	Point t(Fixed(2.5f), Fixed(2.49f));
	if (bsp(p1, p2, p3, t))
		std::cout << "Le point " << t << " fait partie du triangle." << std::endl;
	else
		std::cout << "Le point " << t << " ne fait pas partie du triangle." << std::endl;

	return 0;
}