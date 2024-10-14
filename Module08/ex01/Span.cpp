#include "Span.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Span::Span() : _N(0){
}
Span::Span(unsigned int N) : _N(N){
}
Span::Span(const Span& copy){
	*this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Span::~Span(){
}

////////// OPERATOR /////////////////////////////////////////////////
Span& Span::operator=(const Span& copy){
	if (this == &copy)
		return (*this);
	if (_intVector.size() > 0)
		_intVector.resize(0);
	_intVector.resize(copy._N);
	_intVector.insert(_intVector.begin(), copy._intVector.begin(), copy._intVector.end());
	_N = copy._N;
	return (*this);
}

////////// FUNCTIONS ////////////////////////////////////////////////
void	Span::addNumber(int	nbr){
	unsigned int size = _intVector.size();
	if (_N <= size)
		throw SpanException();
	_intVector.push_back(nbr);
}
unsigned int	Span::shortestSpan(void) const{

	long long span = 4294967295;
	long long tmp;
	if (_intVector.size() < 2)
		throw SpanException();
	for (size_t i = 0; i < _intVector.size(); i++)
	{
		for (size_t j = i + 1; j < _intVector.size(); j++)
		{
			tmp = (long)_intVector[i] - (long)_intVector[j];
			if (tmp < 0)
				tmp *= -1;
			if (tmp < span)
				span = tmp;
		}
	}
	return (span);
}
unsigned int	Span::longestSpan(void) const{
	
	int	max = *std::max_element(_intVector.begin(), _intVector.end());
	int	min = *std::min_element(_intVector.begin(), _intVector.end());
	return max - min;
}
