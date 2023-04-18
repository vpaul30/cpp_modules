#include <iostream>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

static float ft_pow(int base, int pow)
{
	float res = 1;

	if (pow < 0)
		while (pow++)
			res /= base;
	else
		while (pow--)
			res *= base;
	
	return res;
}

Fixed::Fixed() : _fixed_value(0)
{
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called.\n";
	*this = other;
}

Fixed::Fixed(const int number) : _fixed_value(number * ft_pow(2, _bits))
{
	std::cout << "Int constructor called.\n";
}

Fixed::Fixed(const float number) : _fixed_value(number * ft_pow(2, _bits))
{
	std::cout << "Float constructor called.\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called.\n";
	this->_fixed_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called.\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _fixed_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fixed_value = raw;
}

int Fixed::toInt(void) const
{
	return _fixed_value * ft_pow(2, -_bits);
}

float Fixed::toFloat(void) const
{
	return _fixed_value * ft_pow(2, -_bits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	return (stream << fixed.toFloat());
}