#include "whatever.hpp"

// class Awesome
// {
// 	public:
// 		Awesome(int n) : _n(n) {}
// 		bool	operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
// 		bool	operator!=(Awesome const &rhs) const{ return (this->_n != rhs._n); }
// 		bool	operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
// 		bool	operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
// 		bool	operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
// 		bool	operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
// 		int		get_n() { return (_n);}
// 	private:
// 		int _n;
// };

int main(void)
{
	{
		std::cout << "Work with int" << std::endl;
		int int_1 = 21;
		int int_2 = 42;
		std::cout << "Created two numbers of type int" << std::endl;
		std::cout << "first number = " << int_1 << ", second number = " << int_2 << std::endl;
		std::cout << "Swap numbers" << std::endl;
		::swap(int_1, int_2);
		std::cout << "first number = " << int_1 << ", second number = " << int_2 << std::endl;
		std::cout << "min(first number, second number) = " << ::min(int_1, int_2) << std::endl;
		std::cout << "max(first number, second number) = " << ::max(int_1, int_2) << std::endl;
		std::cout << "max(first number, first number) = " << ::max(int_1, int_1) << std::endl;
		std::cout << "\n././././././././././././././././././././././././.\n" << std::endl;
	}
	{
		std::cout << "Work with double" << std::endl;
		double double_1 = 21.42;
		double double_2 = 42.21;
		std::cout << "Created two numbers of type double" << std::endl;
		std::cout << "first number = " << double_1 << ", second number = " << double_2 << std::endl;
		std::cout << "Swap numbers" << std::endl;
		::swap(double_1, double_2);
		std::cout << "first number = " << double_1 << ", second number = " << double_2 << std::endl;
		std::cout << "min(first number, second number) = " << ::min(double_1, double_2) << std::endl;
		std::cout << "max(first number, second number) = " << ::max(double_1, double_2) << std::endl;
		std::cout << "\n././././././././././././././././././././././././.\n" << std::endl;
	}
	{
		std::cout << "Work with string" << std::endl;
		std::string str_1 = "school 21";
		std::string str_2 = "school 42";
		std::cout << "Created two strings" << std::endl;
		std::cout << "first string = " << str_1 << ", second string = " << str_2 << std::endl;
		std::cout << "Swap strings" << std::endl;
		::swap(str_1, str_2);
		std::cout << "first string = " << str_1 << ", second string = " << str_2 << std::endl;
		std::cout << "min(first string, second string) = " << ::min(str_1, str_2) << std::endl;
		std::cout << "max(first string, second string) = " << ::max(str_1, str_2) << std::endl;
		std::cout << "\n././././././././././././././././././././././././.\n" << std::endl;
	}
	// {
	// 	std::cout << "Work with new class" << std::endl;
	// 	Awesome obj_1(21);
	// 	Awesome obj_2(42);
	// 	Awesome temp(1);
	// 	std::cout << "Created two objects" << std::endl;
	// 	std::cout << "first object = " << obj_1.get_n() << ", second object = " << obj_2.get_n() << std::endl;
	// 	std::cout << "Swap objects" << std::endl;
	// 	::swap(obj_1, obj_2);
	// 	std::cout << "first object = " << obj_1.get_n() << ", second object = " << obj_2.get_n() << std::endl;
	// 	temp = ::min(obj_1, obj_2);
	// 	std::cout << "min(first object, second object) = " << temp.get_n() << std::endl;
	// 	temp = ::max(obj_1, obj_2);
	// 	std::cout << "max(first object, second object) = " << temp.get_n() << std::endl;
	// }
}