#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
    	int					_rawBits;
		static int const	_nbrBit = 8;

	public:
    	Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& copy);

		Fixed&	operator=(const Fixed& overload);

		// Comparison operators : > , < , >= , <= , == , !=
		bool	operator>(const Fixed& a) const;
		bool	operator<(const Fixed& a) const;
		bool	operator>=(const Fixed& a) const;
		bool	operator<=(const Fixed& a) const;
		bool	operator==(const Fixed& a) const;
		bool	operator!=(const Fixed& a) const;

		// Arithmetic operators : + , - , * , /
		Fixed	operator+(const Fixed& a);
		Fixed	operator-(const Fixed& a);
		Fixed	operator*(const Fixed& a);
		Fixed	operator/(const Fixed& a);

		// Increment and decrement operators : ++ , --
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed&	operator++(void);
		Fixed&	operator--(void);

    	~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& n);

#endif
