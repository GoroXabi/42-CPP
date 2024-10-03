#include "Point.hpp"
#include "Fixed.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Point::Point(): x(0), y(0) {}

Point::Point(const float x_value, const float y_value): x(x_value), y(y_value) {}

Point::Point(Point &model): x(model.x), y(model.y) {}

Point &Point::operator=(const Point &model)
{
	this->~Point();
	new(this) Point(model.x.toFloat(), model.y.toFloat());
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Point::~Point() {
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

float Point::get_x_float(void) const{
	return (x.toFloat());
}

float Point::get_y_float(void) const{
	return (y.toFloat());
}