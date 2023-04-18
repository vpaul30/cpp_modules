#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int		index = 0;
		int		amount = 0;
		Contact contacts[8];
	public:
		void print_contact(int index);
		void add_contact();
		void search();
	private:
		std::string fit_string(std::string text);
		std::string get_input();
		std::string get_index();
};

#endif