#include "Fixed.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Fixed::Fixed() {
	_rawBits = 0;
}
Fixed::Fixed(const int i) {
	_rawBits = i << _nbrBit;
}
Fixed::Fixed(const float f) {
	_rawBits = roundf(f * (1 << _nbrBit));
}
Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Fixed::~Fixed() {
}

////////// OPERATORS ////////////////////////////////////////////////
Fixed&   Fixed::operator=(const Fixed& overload) {
	_rawBits = overload.getRawBits();
	return *this;
}
std::ostream&	operator<<(std::ostream& outputStream, const Fixed& n) {
	outputStream << n.toFloat();
	return outputStream;
}
//-------- COMPARISON OPERATORS -----------------------------------//
bool	Fixed::operator>(const Fixed& a) const {
	if (this->getRawBits() > a.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator<(const Fixed& a) const {
	if (this->getRawBits() < a.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator>=(const Fixed& a) const {
	if (this->getRawBits() >= a.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator<=(const Fixed& a) const {
	if (this->getRawBits() <= a.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator==(const Fixed& a) const {
	if (a.getRawBits() == this->getRawBits())
		return true;
	return false;
}
bool	Fixed::operator!=(const Fixed& a) const {
	if (a.getRawBits() != this->getRawBits())
		return true;
	return false;
}
//-------- ARITHMETIC OPERATORS -------------------------------------
Fixed	Fixed::operator+(const Fixed& a) {
	Fixed fixed = this->toFloat() + a.toFloat();
	return fixed;
}
Fixed	Fixed::operator-(const Fixed& a) {
	Fixed fixed = this->toFloat() - a.toFloat();
	return fixed;
}
Fixed	Fixed::operator*(const Fixed& a) {
	Fixed fixed = this->toFloat() * a.toFloat();
	return fixed;
}
Fixed	Fixed::operator/(const Fixed& a) {
	Fixed fixed = this->toFloat() / a.toFloat();
	return fixed;
}
//-------- INCREMENT AND DECREMENT OPERATORS ------------------------
Fixed	Fixed::operator++(int) {
	Fixed	fixed = *this;
	_rawBits++;
	return fixed;
}
Fixed	Fixed::operator--(int) {
	Fixed	fixed = *this;
	_rawBits--;
	return fixed;
}
Fixed&	Fixed::operator++(void) {
	_rawBits++;
	return *this;
}
Fixed&	Fixed::operator--(void) {
	_rawBits--;
	return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
int		Fixed::getRawBits(void) const {
	return _rawBits;
}
void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

////////// FUNCTIONS ////////////////////////////////////////////////
float Fixed::toFloat(void) const {
	return ((float)_rawBits / (1 << _nbrBit));
}
int Fixed::toInt(void) const {
	return (_rawBits >> _nbrBit);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	Fixed	fixedA = a;
	Fixed	fixedB = b;
	if (fixedA < fixedB)
		return a;
	return b;
}
Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	Fixed	fixedA = a;
	Fixed	fixedB = b;
	if (fixedA > fixedB)
		return a;
	return b;
}
