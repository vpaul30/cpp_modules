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

// constructrors/destructor

Fixed::Fixed() : _fixed_value(0)
{
	// std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called.\n";
	*this = other;
}

Fixed::Fixed(const int number) : _fixed_value(number * ft_pow(2, _bits))
{
	// std::cout << "Int constructor called.\n";
}

Fixed::Fixed(const float number) : _fixed_value(number * ft_pow(2, _bits))
{
	// std::cout << "Float constructor called.\n";
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called.\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called.\n";
	this->_fixed_value = other.getRawBits();
	return *this;
}

// comparison operators

bool Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->getRawBits() != other.getRawBits();
}

// math operators

Fixed &Fixed::operator+(const Fixed &other)
{
	this->_fixed_value = (this->toFloat() + other.toFloat()) * ft_pow(2, _bits);
	return *this;
}

Fixed &Fixed::operator-(const Fixed &other)
{
	this->_fixed_value = (this->toFloat() - other.toFloat()) * ft_pow(2, _bits);
	return *this;
}

Fixed &Fixed::operator*(const Fixed &other)
{
	this->_fixed_value = (this->toFloat() * other.toFloat()) * ft_pow(2, _bits);
	return *this;
}

Fixed &Fixed::operator/(const Fixed &other)
{
	this->_fixed_value = (this->toFloat() / other.toFloat()) * ft_pow(2, _bits);
	return *this;
}

// increment/decrement

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp;

	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp;

	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

// min/max

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first <= second)
		return first;
	else
		return second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first <= second)
		return first;
	else
		return second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first >= second)
		return first;
	else
		return second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first >= second)
		return first;
	else
		return second;
}

// member functions

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return _fixed_value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n";
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

//

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	return (stream << fixed.toFloat());
}