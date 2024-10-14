
#ifndef		MUTANSTACK_HPP
# define	MUTANSTACK_HPP

# include	<deque>
# include	<stack>
# include	<iostream>

template <typename T, class CONTAINER = std::deque<T> >
class MutantStack : public std::stack<T>
{	
	public:
		MutantStack() {
		}
		MutantStack(const MutantStack& copy) {
			*this = copy;
		}
		~MutantStack() {
		}

		MutantStack& operator=(const MutantStack& copy) {
			if (this == &copy)
			 return *this;
			this->c = copy.c;
			return *this;
		}

		typedef typename CONTAINER::iterator iterator;

		iterator	begin() {
			return (this->c.begin());
		}
		iterator	end() {
			return (this->c.end());
		}
};

#endif