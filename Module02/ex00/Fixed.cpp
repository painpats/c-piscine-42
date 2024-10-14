#include "Fixed.hpp"

//default constructor
Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

//copy constructor : className (const className& obj)
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = copy.getRawBits();
}

//overload operator=
Fixed&   Fixed::operator=(const Fixed& overload)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = overload.getRawBits();
    return *this;
}

//destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}
