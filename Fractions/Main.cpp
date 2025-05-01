#include <iostream>
#include "Fraction.h"


    int main()
    {
        using namespace mathlib;
        Fraction<int> fraction1{ 15, 5 };
        std::cout << fraction1 << std::endl;

        Fraction<int> fraction2{ 15, 6 };
        fraction2.Simplify();
        std::cout << fraction2 << std::endl;

        std::cout << fraction1 << " == " << fraction2 << " result: " << (fraction1 == fraction2) << std::endl;
        std::cout << fraction1 << " > " << fraction2 << " result: " << (fraction1 > fraction2) << std::endl;

        std::cout << fraction1 << " + " << fraction2 << " result: " << (fraction1 + fraction2) << std::endl;
        std::cout << fraction1 << " * " << fraction2 << " result: " << (fraction1 * fraction2) << std::endl;

        Fraction<int> fraction3;
        std::cout << "input fraction (numerator - denominator): \n";
        std::cin >> fraction3;
        std::cout << fraction3 << std::endl;
        std::cout << fraction3.toDouble() << std::endl;
    }
}