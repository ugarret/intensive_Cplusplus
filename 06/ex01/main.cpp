#include <iostream>

struct Data
{
	int i;
	float f;
};

static uintptr_t serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

static Data *deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data my_struct;
	my_struct.i = 42;
	my_struct.f = 4.2f;
	uintptr_t int_ptr = serialize(&my_struct);	// получаем целое число, размер которого в точности равен размеру указателя
	// std::cout << int_ptr->i << std::endl;	// поскольку uintptr_t - это целое число, то использовать оператор
	// std::cout << int_ptr->f << std::endl;	// -> мы не сможем => получить данные, лежащие в структуре нельзя
	Data *ptr_on_struct = deserialize(int_ptr);	// получаем указатель на структуру
	std::cout << ptr_on_struct->i << std::endl;
	std::cout << ptr_on_struct->f << std::endl;
	return (0);
}