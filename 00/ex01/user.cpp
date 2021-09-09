#include <iostream>
#include "user.hpp"

void user::set_first_name()
{
	std::getline(std::cin, first_name);
}

void user::set_last_name()
{
	std::getline(std::cin, last_name);
}

void user::set_nickname()
{
	std::getline(std::cin, nickname);
}

void user::set_phone_number()
{
	std::getline(std::cin, phone_number);
}

void user::set_darkest_secret()
{
	std::getline(std::cin, darkest_secret);
}

std::string	user::get_first_name()
{
	return first_name;
}

std::string	user::get_last_name()
{
	return last_name;
}

std::string	user::get_nickname()
{
	return nickname;
}

std::string	user::get_phone_number()
{
	return phone_number;
}

std::string	user::get_darkest_secret()
{
	return darkest_secret;
}
