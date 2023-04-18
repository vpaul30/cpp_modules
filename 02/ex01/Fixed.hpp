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
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed);

#endif