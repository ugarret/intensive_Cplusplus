#include <iostream>
#include <fstream>

void print_error(std::string error)
{
	std::cout << error << std::endl;
	exit(0);
}

void check_arguments(int argc, char **argv)
{
	if (argc != 4)
		print_error("Arguments must be 3!!!");
	else if (argv[2][0] == '\0' || argv[3][0] == '\0')
		print_error("S1 and s2 cannot be empty");
	else
		return ;
}

std::string replace_s1_with_s2(std::string buffer, char **argv)
{
	size_t pos = 0;
	std::string s1 (argv[2]);
	std::string s2 (argv[3]);
    while((pos = buffer.find(s1, pos)) != std::string::npos)	//It actually means until the end of the string
    {
        buffer.erase(pos, s1.size());							//To remove (size) characters from the calling string, starting at pos
        buffer.insert(pos, s2);									//Insert a s2, starting at pos
		pos += s2.size();
	}
	return buffer;
}

std::string read_file(char **argv)
{
	std::ifstream 	file(argv[1]);
	std::string		buffer("");
	std::string 	str;

	if (!file.is_open())
		print_error("File does not exist");
	while (std::getline(file, str))
	{
		buffer += str;
		if (!file.eof())
			buffer += "\n";
	}
	file.close();
	return replace_s1_with_s2(buffer, argv);
}

void writing_to_file(std::string buffer, std::string filename)
{
	for (int i = 0; filename[i]; ++i)
		filename[i] = toupper(filename[i]);
	std::ofstream file(filename + ".replace");
	if (!file.is_open())
		print_error("File does not created");
	file << buffer;
	file.close();
}

int main(int argc, char **argv)
{
	std::string ready_buf;
	check_arguments(argc, argv);
	ready_buf = read_file(argv);
	writing_to_file(ready_buf, argv[1]);
}
