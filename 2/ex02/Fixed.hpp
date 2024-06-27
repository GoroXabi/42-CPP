#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class	Fixed
{
private:

	int 				value;
	static const int	fractional_bits = 8;

public:

/*--------------------CONSTRUCTORS-------------------*/

	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &model);
	Fixed &operator=(const Fixed &model);

/*--------------------DESTRUCTORS--------------------*/

	~Fixed();

/*--------------------COMPARISON---------------------*/

	bool operator>(const Fixed &to_compare);
	bool operator<(const Fixed &to_compare);
	bool operator>=(const Fixed &to_compare);
	bool operator<=(const Fixed &to_compare);
	bool operator==(const Fixed &to_compare);
	bool operator!=(const Fixed &to_compare);

/*--------------------ARITHMETIC---------------------*/

	Fixed	operator+(const Fixed &to_compare);
	Fixed	operator-(const Fixed &to_compare);
	Fixed	operator*(const Fixed &to_compare);
	Fixed	operator/(const Fixed &to_compare);

/*----------------INCREMENT/DECREMENT----------------*/

	Fixed	operator++();
	Fixed	operator++(int to_sum);
	Fixed	operator--();
	Fixed	operator--(int to_rest);

/*-----------------MIN_MAX_FUNCTIONS-----------------*/

	static Fixed &min(Fixed &one, Fixed &two);
	static Fixed &max(Fixed &one, Fixed &two);
	static Fixed &min(const Fixed &one, const Fixed &two);
	static Fixed &max(const Fixed &one, const Fixed &two);

/*-----------------PUBLIC_FUNCTIONS------------------*/

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
};

/*-----------------OVERLOAD_OPERATOR-----------------*/

	std::ostream &operator<<(std::ostream &num, const Fixed &fixed_num);

#endif
