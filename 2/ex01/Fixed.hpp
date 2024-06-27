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

	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &model);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

	std::ostream &operator<<(std::ostream &num, const Fixed &fixed_num);

#endif
