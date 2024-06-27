#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &model)
{
	std::cout << "Copy constructor called" << std::endl;
	value = model.value;
}

Fixed &Fixed::operator=(const Fixed &model)
{
	value = model.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::Fixed(const int new_int) {
	std::cout << "Int constructor called" << std::endl;
	value = roundf(new_int * (1 << fractional_bits));
}

Fixed::Fixed(const float new_float) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(new_float * (1 << fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const{
	return (roundf(value) / (1 << fractional_bits));
}

int	Fixed::toInt(void) const{
	return (value) / (1 << fractional_bits);
}

int	Fixed::getRawBits(void) const{
	return (value);
}

void	Fixed::setRawBits(const int raw) {
	value = raw;
}

std::ostream &operator<<(std::ostream &num, const Fixed &fixed_num)
{
	num << fixed_num.toFloat();
	return(num);
}