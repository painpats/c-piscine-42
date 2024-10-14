#include "whatever.hpp"

int	main( void ) {

	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "swap(2,3): a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "swap(chaine1,chaine2): c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;

	float	e = 4.2;
	float	f = 2.4;
	::swap(e, f);
	std::cout << "swap(4.2,2.4): e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min( e, f ) << std::endl;
	std::cout << "max(e, f) = " << ::max( e, f ) << std::endl;
	std::cout << std::endl;

	char	g = 'g';
	char	h = 'b';
	std::cout << "swap(g,b): g = " << g << ", b = " << h << std::endl;
	std::cout << "min(g, b) = " << ::min( g, h ) << std::endl;
	std::cout << "max(g, b) = " << ::max( g, h ) << std::endl;
	std::cout << std::endl;

	return 0;
}
