#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int num = rand() % 3;

	switch(num)
	{
	case 0:
		std::cout << "A generated\n";
		return new A();
	case 1:
		std::cout << "B generated\n";
		return new B();
	case 2:
		std::cout << "C generated\n";
		return new C();
	}
	return NULL;
}

void identify(Base *p)
{
		if (dynamic_cast<A *>(p))
		{
			std::cout << "A";
			return;
		}
		if (dynamic_cast<B *>(p))
		{
			std::cout << "B";
			return;
		}
		if (dynamic_cast<C *>(p))
		{
			std::cout << "C";
			return;
		}
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch(std::exception &e)
	{}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch(std::exception &e)
	{}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C";
	}
	catch(std::exception &e)
	{}
}

int main()
{
	srand(time(NULL));

	Base *base = generate();
	std::cout << "identify(pointer): ";
	identify(base);
	std::cout << std::endl;
	std::cout << "identify(reference): ";
	identify(*base);
	std::cout << std::endl;

	delete base;
	return 0;
}