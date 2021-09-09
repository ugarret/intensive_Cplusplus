#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "user.hpp"

class phonebook
{
	public:
		void	search_user_by_index(phonebook phonebook, int max);
		void	add_user(phonebook *phonebook, int i);
		void	set_user(user new_user, int i);
		user	get_user(int i);
	private:
		user	persons[8];
};

#endif