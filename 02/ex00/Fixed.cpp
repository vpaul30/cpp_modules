#include <iostream>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _fixed_value(0)
{
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called.\n";
	*this = other;
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
	return 0;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fixed_value = raw;
}