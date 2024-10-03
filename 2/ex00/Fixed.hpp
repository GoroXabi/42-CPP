#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{

public:

	Fixed();
	Fixed(const Fixed &model);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int 				value;
	static const int	fractional_bits = 8;

};

#endif
