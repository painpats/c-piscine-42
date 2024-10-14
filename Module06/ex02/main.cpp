#include <iostream>
#include <cstdlib>
#include <cctype>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base    *gen;

    gen = generate();
    std::cout << "A, B or C ? A Base have been randomly generate" << std::endl;
    identify(gen);
    identify(*gen);
    delete gen;
    return 0;
}

////////// FUNCTIONS ////////////////////////////////////////////////
Base*   generate(void) {
    srand(time(0));
    switch (rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}
void    identify(Base* p) {
    A   *a;
    a = dynamic_cast<A*>(p);

    B   *b;
    b = dynamic_cast<B*>(p);

    C   *c;
    c = dynamic_cast<C*>(p);

    if (a)
        std::cout << "p is pointed by the actual type 'A'" << std::endl;
    else if (b)
        std::cout << "p is pointed by the actual type 'B'" << std::endl;
    else if (c)
        std::cout << "p is pointed by the actual type 'C'" << std::endl;
	else
		std::cout << "Error" << std::endl;
}
void    identify(Base& p) {
    try
    {
		A	a = dynamic_cast<A&>(p);
		std::cout << "p is pointed by the actual type 'A'" << std::endl;

    }
	catch(const std::exception& e) {}
    try
    {
		B	b = dynamic_cast<B&>(p);
		std::cout << "p is pointed by the actual type 'B'" << std::endl;

    }
	catch(const std::exception& e) {}
    try
    {
		C	c = dynamic_cast<C&>(p);
		std::cout << "p is pointed by the actual type 'C'" << std::endl;

    }
	catch(const std::exception& e) {}
}
