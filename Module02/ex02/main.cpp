#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl; // 0
    std::cout << ++a << std::endl; //0.00390625
    std::cout << a << std::endl; //0.00390625
    std::cout << a++ << std::endl; //0.00390625
    std::cout << a << std::endl; // 0.0078125

    std::cout << b << std::endl; //10.1016

    std::cout << Fixed::max( a, b ) << std::endl; //10.1016

	std::cout << "\nMY TEST :" << std::endl;
    Fixed   c = a;
    Fixed   d( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << Fixed::min(c, d) << std::endl; // 0.0078125
	std::cout << d / Fixed(2) << std::endl; // 5.05078
	std::cout << d + Fixed(-3.14f) << std::endl; // 6.96094
	std::cout << d - Fixed(18) << std::endl; // -7.89844
	std::cout << (c <= d) << std::endl; // 1
	std::cout << (c >= d) << std::endl; // 0
	std::cout << (c != a) << std::endl; // 0
	std::cout << (c == a) << std::endl; // 1
    return 0;
}
