#include <iostream>
#include <string>


class Number
{
public:
	Number(int value) : _value(value) 
	{
		std::cout << "Number with value " << _value << " constructed\n";
	}
	~Number()
	{
		std::cout << "Number with value " << _value << " destructed\n";
	}

	Number &operator=(Number &other)
	{
		this->_value = other._value;
		return *this;
	}

	Number operator++(int)
	{
		std::cout << "post-increment\n";

		Number temp = *this;

		this->_value = this->_value + 1;

		return temp;
	}

	Number &operator++(void)
	{
		std::cout << "pre-increment\n";
		this->_value = this->_value + 1;
		return *this;
	}

	int getValue() const
	{
		return _value;
	}

	static void Print_0()
	{
		std::cout << "Thats 0!\n";
	}

 	static int getBytes()
	{
		return _bytes;
	}

private:
	int _value;
	const static int _bytes = 8;
};

std::ostream &operator<<(std::ostream &COUT, const Number &number)
{
	COUT << number.getValue();
	return COUT;
}

int main()
{
	Number a(0);

	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "Bytes " << Number::getBytes() << std::endl;

	// a++;
}