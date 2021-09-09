#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(): _size(0)
		{
			_array = new T[_size]();
		};

        Array(unsigned int n): _size(n)
		{
			_array = new T[_size]();
		};

		Array(const Array &other)
		{
			this->operator=(other);
		};

		Array &operator=(const Array &other)
		{
			if (this == &other)
				return (*this);
			_size = other._size;
			_array = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
			return (*this);
		};

        virtual ~Array()
		{
			delete[] _array;
		};

        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw out_of_the_limits();
            return (this->_array[index]);
        };

		class out_of_the_limits: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("This element is out of the limits");
				};
		};
};

#endif