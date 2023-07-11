#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;

    ScalarConverter::convert(argv[1]);

    // TESTS
    // std::cout << "=== A ===\n";
    // ScalarConverter::convert("A");
    // std::cout << "\n=== 5 ===\n";
    // ScalarConverter::convert("5");
    // std::cout << "\n=== 42.0f ===\n";
    // ScalarConverter::convert("42.0f");
    // std::cout << "\n=== 104.123f ===\n";
    // ScalarConverter::convert("104.123f");
    // std::cout << "\n=== 21.0 ===\n";
    // ScalarConverter::convert("21.0");
    // std::cout << "\n=== 205.3 ===\n";
    // ScalarConverter::convert("205.3");
    // std::cout << "\n=== +inff ===\n";
    // ScalarConverter::convert("+inff");
    // std::cout << "\n=== -inff ===\n";
    // ScalarConverter::convert("-inff");
    // std::cout << "\n=== nanf ===\n";
    // ScalarConverter::convert("nanf");
    // std::cout << "\n=== +inf ===\n";
    // ScalarConverter::convert("+inf");
    // std::cout << "\n=== -inf ===\n";
    // ScalarConverter::convert("-inf");
    // std::cout << "\n=== nan ===\n";
    // ScalarConverter::convert("nan");

    return 0;
}