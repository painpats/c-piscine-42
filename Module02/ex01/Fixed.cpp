#include "Fixed.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Fixed::Fixed() 
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = i << _nbrBit;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * (1 << _nbrBit));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

////////// OPERATORS ////////////////////////////////////////////////
Fixed&   Fixed::operator=(const Fixed& overload)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = overload.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& n)
{
	outputStream << n.toFloat();
	return outputStream;
}

////////// GETTER-SETTER ////////////////////////////////////////////
int		Fixed::getRawBits(void) const
{
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

////////// FUNCTIONS ////////////////////////////////////////////////
float Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _nbrBit));
}

int Fixed::toInt(void) const
{
	return (_rawBits >> _nbrBit);
}
