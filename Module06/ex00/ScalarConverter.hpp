#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <cctype>
# include <cmath>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& copy);

	public:
		static void	convert(std::string str);
};

#endif