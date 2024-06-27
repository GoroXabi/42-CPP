#include <iostream>
#include <ostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point	point_a(0, 1);
	Point	point_b(4.5, 5.5);
	Point	point_c(8, 2);
	
	Point	point1(4, 3);
	Point	point2(5, 5);
	Point	point3(-4.5, 8.3);

	if (bsp(point_a, point_b, point_c, point1))
		std::cout << "point1 is inside" << std::endl;
	else
		std::cout << "point1 is outside" << std::endl;

	if (bsp(point_a, point_b, point_c, point2))
		std::cout << "point2 is inside" << std::endl;
	else
		std::cout << "point2 is outside" << std::endl;

	if (bsp(point_a, point_b, point_c, point3))
		std::cout << "point3 is inside" << std::endl;
	else
		std::cout << "point3 is outside" << std::endl;

	return 0;
}
