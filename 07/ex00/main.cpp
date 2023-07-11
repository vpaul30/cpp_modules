#include "whatever.hpp"
#include <iostream>

int main()
{
	// swap
	std::cout << "===swap===\n";
	{
		int one = 1;
		int two = 2;

		std::cout << "one = " << one << std::endl;
		std::cout << "two = " << two << std::endl;

		swap(one, two);
		std::cout << "swapped\n";
		
		std::cout << "one = " << one << std::endl;
		std::cout << "two = " << two << std::endl;
	}

	// min
	std::cout << "\n===min===\n";
	{
		int one = 1;
		int two = 2;

		std::cout << "one = " << one << std::endl;
		std::cout << "two = " << two << std::endl;

		int min_res = min(one, two);
		std::cout << "min_res = " << min_res << std::endl;
	}

	// max
	std::cout << "\n===max===\n";
	{
		int one = 1;
		int two = 2;

		std::cout << "one = " << one << std::endl;
		std::cout << "two = " << two << std::endl;

		int max_res = max(one, two);
		std::cout << "max_res = " << max_res << std::endl;
	}
	
	// example from pdf
	//
	// a = 3, b = 2
	// min(a, b) = 2
	// max(a, b) = 3
	// c = chaine2, d = chaine1
	// min(c, d) = chaine1
	// max(c, d) = chaine2
	std::cout << "\n===PDF===\n";
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

}