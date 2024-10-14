#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <stack>

void	rpn(char **av);

/***** Exception ***************************************************/
class ExecErrorException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Error";
		}
};

#endif
