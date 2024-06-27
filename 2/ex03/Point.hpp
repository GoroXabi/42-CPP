#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <ostream>
#include <cmath>
#include "Fixed.hpp"

class	Point
{
private:
	Fixed const x;
	Fixed const y;
public:

/*--------------------CONSTRUCTORS-------------------*/
	Point();
	Point(const float x_value, const float y_value);
	Point(Point &model);
	Point &operator=(const Point &model);

/*--------------------DESTRUCTORS--------------------*/

	~Point();


/*-----------------PUBLIC_FUNCTIONS------------------*/

	float get_x_float(void) const;
	float get_y_float(void) const;
};

/*-----------------OTHER_FUNCTIONS------------------*/

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
