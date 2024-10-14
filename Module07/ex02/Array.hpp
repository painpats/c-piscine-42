#ifndef		ARRAY_HPP
# define	ARRAY_HPP

# include	<iostream>
# include	<exception>
# include	<cstdlib>

template<class T>
class Array
{
	private:
		T*				_array;
		unsigned int	_n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();

		Array& operator=(const Array& copy);
		T& operator[](unsigned int index);
		unsigned int	size()	const;
};

template<class T>
Array<T>::Array() : _n(0){
	_array = new T[_n]();
}

template<class T>
Array<T>::Array(unsigned int n) : _n(n) {
	_array = new T[_n]();
}

template<class T>
Array<T>::Array(const Array<T>& copy){
	_array = new T[copy._n]();
	for (unsigned int i = 0; i < copy._n; i++) {
		_array[i] = copy._array[i];
	}
	_n = copy._n;
}

template<class T>
Array<T>::~Array(void){
	if (_array)
		delete [] _array;
	return ;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &copy){
	if (this == &copy)
		return *this;
	if (_array)
		delete _array;
	new (this) Array<T> (copy);
	return *this;
}

template<class T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _n) {
        throw std::exception();
    }
    return _array[index];
}

template<class T>
unsigned int	Array<T>::size() const{
	return (_n);
}

#endif