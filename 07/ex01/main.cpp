#include "iter.hpp"

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print(T const &x)
// {
// 	std::cout << x << std::endl;
// 	return;
// }

// int main()
// {
// 	Awesome tab2[5];

// 	iter(tab2, 5, print);

// 	return 0;
// }


int main()
{
	size_t lenght = 4;
	float floats[4] = {1.01f, 2.01f, 3.01f, 4.01f};
	char chars[4] = {'a', 'b', 'c', 'd'};

	std::cout << "Array of floats: " << std::endl;
	::iter(floats, lenght, print_element);
	std::cout << "\n\n";
	std::cout << "Changed array of floats->ints: " << std::endl;
	::iter(floats, lenght, cast_to_int_and_print);
	std::cout << "\n\n";
	std::cout << "Array of chars: " << std::endl;
	::iter(chars, lenght, print_element);
	std::cout << "\n\n";
	std::cout << "Changed array of chars->ints: " << std::endl;
	::iter(chars, lenght, cast_to_int_and_print);
	std::cout << "\n\n";
}