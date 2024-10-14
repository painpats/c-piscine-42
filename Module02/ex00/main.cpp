#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "\nMY TEST :" << std::endl;
	Fixed	d;
	a.setRawBits(42);
	c = a;
	std::cout << a.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
