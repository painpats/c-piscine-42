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

    	~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& n);

#endif
