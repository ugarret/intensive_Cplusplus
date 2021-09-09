#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen karusha;
	if (argc == 2)
		karusha.karenFilter(argv[1]);
	else
		std::cout << "it seems, Karen said nothing or said too much\n";
	return 0;
}