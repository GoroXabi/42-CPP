#include "Fixed.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &model)
{
	value = model.value;
}

Fixed &Fixed::operator=(const Fixed &model)
{
	value = model.value;
	return (*this);
}

Fixed::Fixed(const int new_int) {
	value = roundf(new_int * (1 << fractional_bits));
}

Fixed::Fixed(const float new_float) {
	value = roundf(new_float * (1 << fractional_bits));
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Fixed::~Fixed() {
}

/*--------------------------------------------------------------*/
/*							COMPARISON							*/
/*--------------------------------------------------------------*/

bool	Fixed::operator>(const Fixed &to_compare)
{
	if (value > to_compare.value)
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &to_compare)
{
	if (value < to_compare.value)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &to_compare)
{
	if (value >= to_compare.value)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &to_compare)
{
	if (value <= to_compare.value)
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &to_compare)
{
	if (value == to_compare.value)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &to_compare)
{
	if (value != to_compare.value)
		return true;
	return false;
}

/*--------------------------------------------------------------*/
/*							ARITHMETIC							*/
/*--------------------------------------------------------------*/

Fixed	&Fixed::operator+(const Fixed &to_compare){
	value += to_compare.value;
	return *this;
}

Fixed	&Fixed::operator-(const Fixed &to_compare){
	value -= to_compare.value;
	return *this;
}

Fixed	&Fixed::operator*(const Fixed &to_compare){
	 value = (value * (to_compare.value >> fractional_bits));
	return *this;
}

Fixed	&Fixed::operator/(const Fixed &to_compare){
		 value = (value / (to_compare.value >> fractional_bits));
	return *this;
}

/*--------------------------------------------------------------*/
/*						INCREMENT/DECREMENT						*/
/*--------------------------------------------------------------*/

Fixed	Fixed::operator++() {
	++value;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	++value;
	return (tmp);
}

Fixed	Fixed::operator--() {
	--value;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	--value;
	return (tmp);
}

/*--------------------------------------------------------------*/
/*						MIN_MAX_FUNCTIONS						*/
/*--------------------------------------------------------------*/

Fixed &Fixed::min(Fixed &one, Fixed &two)
{
	if (one.value <= two.value)
		return one;
	return two;
}

Fixed &Fixed::max(Fixed &one, Fixed &two)
{
	if (one.value >= two.value)
		return one;
	return two;
}

Fixed &Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one.value <= two.value)
		return ((Fixed &)one);
	return ((Fixed &)two);
}

Fixed &Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one.value >= two.value)
		return ((Fixed &)one);
	return ((Fixed &)two);
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

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

/*--------------------------------------------------------------*/
/*						OVERLOAD_OPERATOR						*/
/*--------------------------------------------------------------*/

std::ostream &operator<<(std::ostream &num, const Fixed &fixed_num)
{
	num << fixed_num.toFloat();
	return(num);
}
