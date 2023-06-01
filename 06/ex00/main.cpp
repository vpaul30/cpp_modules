#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

bool isRounded(double number) {
    return (number == static_cast<int>(number));
}

int main(int argc, char **argv)
{
    // std::cout << "TEST CASTS\n";

    // double numbers[] = {1, 2.345, 3, 4.56789, 5};
    
    // std::ios defaultCout(nullptr);
    // defaultCout.copyfmt(std::cout);

    // for (double item : numbers)
    // {
    //     if (isRounded(item))
    //         std::cout << std::fixed << std::setprecision(1) << item << "f" << std::endl;
    //     else
    //     {
    //         std::cout.copyfmt(defaultCout);
    //         std::cout << item << "f" << std::endl;
    //     }
    // }

    // ScalarConverter test("-123.354f");
    // test.convert();
    ScalarConverter::convert(argv[1]);

    // std::string input;

    // std::cout << "enter literal:\n";
    // std::cin >> input;
    // std::cout << "input = " << input << std::endl;

    // double _double = std::atof(input.c_str());
    // std::cout << "double = " << _double << std::endl;
    return 0;
}