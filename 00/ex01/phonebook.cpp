#include <iostream>
#include "phonebook.hpp"

void	phonebook::set_user(user new_user, int i)
{
	persons[i - 1] = new_user;
}

user	phonebook::get_user(int i)
{
	return persons[i - 1];
}

void phonebook::add_user(phonebook *phonebook, int i)
{
	user new_user;
	std::cout << "Enter first name" << std::endl;
	new_user.set_first_name();
	std::cout << "Enter last name" << std::endl;
	new_user.set_last_name();
	std::cout << "Enter nickname" << std::endl;
	new_user.set_nickname();
	std::cout << "Enter phone number" << std::endl;
	new_user.set_phone_number();
	std::cout << "Enter darkest secret" << std::endl;
	new_user.set_darkest_secret();
	phonebook->set_user(new_user, i);
}

static void shortening_of_word(std::string word)
{
	int len = word.length();
	std::string temp = word;
	if (len == 10)
		std::cout << word << "|";
	else if (len > 10)
	{
		temp.resize(9);
		std::cout << temp << ".|";
	}
	else
	{
		for (len = 10 - len; len > 0; --len)
				std::cout << " ";
		std::cout << temp << "|";
	}
}

static void	print_phonebook(phonebook phonebook, int max)
{
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|   index  |first name| last name| nickname |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 1; i <= max; ++i)
	{
		user temp = phonebook.get_user(i);
		std::cout << "|         " << i << "|";
		shortening_of_word(temp.get_first_name());
		shortening_of_word(temp.get_last_name());
		shortening_of_word(temp.get_nickname());
		std::cout << std::endl;
		if (i + 1 <= max)
			std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

static int	check_index(std::string str_index)
{
	for (int i = 0; str_index[i] != '\0'; ++i)
	{
		if (str_index[i] < '0' || str_index[i] > '9')
		{
			std::cout << "The index must contain only numbers" << std::endl;
			return 1;
		}
	}
	return 0;
}

void	phonebook::search_user_by_index(phonebook phonebook, int max)
{
	std::cout << "Enter index" << std::endl;
	int index;
	std::string str_index;
	std::getline(std::cin, str_index);
	if (check_index(str_index) || str_index == "\0")
		return ;
	else
		index = std::stoi(str_index);
	if (index < 1 || index > 8)
		std::cout << "The phonebook doesn't support such an index" << std::endl;
	else if (index > max)
		std::cout << "There is no contact with such an index" << std::endl;
	else
	{
		user temp = phonebook.get_user(index);
		std::cout << "First name: " << temp.get_first_name() << std::endl;
		std::cout << "Last name: " << temp.get_last_name() << std::endl;
		std::cout << "Nickname: " << temp.get_nickname() << std::endl;
		std::cout << "Phone number: " << temp.get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << temp.get_darkest_secret() << std::endl;
	}
}

int main()
{
	phonebook phonebook;
	int i = 0;
	int max = 0;
	while (1)
	{
		std::cout << "Enter command" << std::endl;
		std::string command;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		if (command == "EXIT")
			exit (1);
		else if (command == "ADD")
		{
			i++;
			max++;
			if (max > 8)
				max = 8;
			if (i != 8)
				i %= 8;
			phonebook.add_user(&phonebook, i);
		}
		else if (command == "SEARCH")
		{
			if (i == 0)
				std::cout << "You don't have friends yet, but hold on, everything will be fine" << std::endl;
			else
			{
				print_phonebook(phonebook, max);
				phonebook.search_user_by_index(phonebook, i);
			}
		}
		else
			std::cout << "command not found" << std::endl;
	}
	return (0);
}