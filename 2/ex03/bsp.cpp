#include "Point.hpp"

/*
	f(x) = mx + b;
	m = (x1 - x2) / (y1 - y2);
	b = -(mx - y);
	x = (b - y) / m 
*/

struct f_x
{
	float m;
	float b;
};

float	resolve_x(float y, f_x f_n){
	return ((y - f_n.b) / f_n.m);
}

float	get_b(Point const &point, float m) {
	return (-1 * ((m * point.get_x_float()) - point.get_y_float()));
}

float get_m(Point const &one, Point const &two)
{
	float x1 = one.get_x_float();
	float y1 = one.get_y_float();
	float x2 = two.get_x_float();
	float y2 = two.get_y_float();

	if (x1 <= x2) {
		return (y1 - y2) / (x1 - x2);
	} else {
		return (y2 - y1) / (x2 - x1);
	}
}


bool check_true(int sum, float m1, float m2, float m3)
{
	if (sum == 2 && ((m1 < 0 && m2 < 0) || (m2 < 0 && m3 < 0) || (m3 < 0 && m1 < 0)))
		return true;
	if (sum == 1 && ((m1 > 0 && m2 > 0) || (m2 > 0 && m3 > 0) || (m3 > 0 && m1 > 0)))
		return true;
	return false;
}

bool check_crash(Point const &a, Point const &b, Point const &c)
{
	if ((a.get_x_float() == b.get_x_float()) || (b.get_x_float() == c.get_x_float()) || (c.get_x_float() == a.get_x_float()))
		return true;	
	if ((a.get_y_float() == b.get_y_float()) || (b.get_y_float() == c.get_y_float()) || (c.get_y_float() == a.get_y_float()))
		return true;
	return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	f_x		a_b;
	f_x		b_c;
	f_x		c_a;

	bool	bigger_a_b = false;
	bool	bigger_b_c = false;
	bool	bigger_c_a = false;

	if (check_crash(a, b, c)) {
		std::cout << "pls dont be mean and put a triangle which slope isnt 0 or infinite :)" << std::endl;
		return false;
	}

	a_b.m = get_m(a, b);
	b_c.m = get_m(b, c);
	c_a.m = get_m(c, a);

	a_b.b = get_b(a, a_b.m);
	b_c.b = get_b(b, b_c.m);
	c_a.b = get_b(c, c_a.m);

	if (resolve_x(point.get_y_float(), a_b) < point.get_x_float())
		bigger_a_b = true;

	if (resolve_x(point.get_y_float(), b_c) < point.get_x_float())
		bigger_b_c = true;

	if (resolve_x(point.get_y_float(), c_a) < point.get_x_float())
		bigger_c_a = true;

	if (check_true(bigger_a_b + bigger_b_c + bigger_c_a, a_b.m, b_c.m, c_a.m))
		return (true); 

	return (false);
}