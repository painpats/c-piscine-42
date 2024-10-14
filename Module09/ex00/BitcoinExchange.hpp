#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include <cstdlib>
# include <cstring>
# include <map>

void	openFile(char *file);

/***** Exceptions **************************************************/
class InvalidFirstLineException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid first line: must be 'date | value'";
		}
};

class BadArgumentsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: could not open file. (The program must take a file as argument)";
		}
};

class OpenFileException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: could not open file";
		}
};

class InvalidFormatException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid format: each line in this file must use the following format: 'date | value'";
		}
};

class InvalidDateException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid date: (YYYY-MM-DD)";
	
		}
};

class BadInputException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: bad input.";
		}
};

class InvalidDataBaseException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid dataBase: something is wrong with your dataBase";
		}
};

class InvalidValueException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid value: must be either a float or a positive integer";
		}
};

class ValueNegException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid value: not a positive number";
		}
};

class ValueTooLargeException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid value: too large number";
		}
};

#endif