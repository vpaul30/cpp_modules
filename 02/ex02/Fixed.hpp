#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixed_value;
		static const int _bits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();

		Fixed &operator=(const Fixed &other);
		// comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		// math operators
		Fixed &operator+(const Fixed &other);
		Fixed &operator-(const Fixed &other);
		Fixed &operator*(const Fixed &other);
		Fixed &operator/(const Fixed &other);
		// increment/decrement operators
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		// min/max
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first, const Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed);

#endif