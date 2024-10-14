#include "RPN.hpp"

static bool	operationSign(char sign) {
	if (sign == '+' || sign == '-' || sign == '/' || sign == '*')
		return true;
	return false;
}

void	rpn(char **av) {

	std::string		arg = av[1];
	std::stack<double> stack;
	
	for (size_t i=0 ; arg[i] ; i++) {
		if (i%2 == 1 && arg[i] != ' ')
			throw ExecErrorException();
		else if (i%2 == 0 && (!isdigit(arg[i]) && operationSign(arg[i]) == false))
			throw ExecErrorException();
		if (i%2 == 1 && arg[i] == ' ')
			continue;
		if (isdigit(arg[i])) {
			stack.push(arg[i] - 48);
			continue;
		}
		if (stack.size() < 2)
			throw ExecErrorException();

		double	y = stack.top();
		stack.pop();
		double	x = stack.top();

		switch (arg[i]) {
			case '+':
				stack.top() = x+y;
				break;
			case '-':
				stack.top() = x-y;
				break;
			case '/':
				if (y==0)
					throw ExecErrorException();
				stack.top() = x/y;
				break;
			case '*':
				stack.top() = x*y;
				break;
		}
	}
	if (stack.size() > 1)
		throw ExecErrorException();
	std::cout << stack.top() << std::endl;
}
