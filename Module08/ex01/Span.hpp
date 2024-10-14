#ifndef		SPAN_HPP
# define	SPAN_HPP

# include	<cstdlib>
# include	<exception>
# include	<vector>
# include	<iostream>
# include	<algorithm>

class SpanException : public std::exception {
    public:
        /*virtual*/char const *what() const throw() {
            return "Span exception";
        }
};

class Span
{
	private:
		unsigned int		_N;
		
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();

		Span& operator=(const Span& obj);

		std::vector<int>	_intVector;
		void			addNumber(int nbr);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;		
};

#endif