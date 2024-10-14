#include "Span.hpp"

int main() {

    std::cout << "TEST INTRA" << std::endl;

    Span sp = Span(5);

    try
    {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
    }
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}

    std::cout << "MY TEST" << std::endl;
	
	Span	spa = Span(3);
	try
	{
		spa.addNumber(42);
		spa.addNumber(43);
		spa.shortestSpan();
		spa.longestSpan();

		std::cout << spa.shortestSpan() << std::endl;
		std::cout << spa.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	Span	span = Span(3);
	try
	{
		span.addNumber(42);
		span.shortestSpan();
		span.longestSpan();

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	Span	spanc = Span(3);
	try
	{
		spanc.addNumber(42);
		spanc.addNumber(42);
		spanc.shortestSpan();
		spanc.longestSpan();

		std::cout << spanc.shortestSpan() << std::endl;
		std::cout << spanc.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	
	return 0;
}
