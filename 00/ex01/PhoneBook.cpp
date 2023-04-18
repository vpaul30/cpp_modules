#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string PhoneBook::get_input()
{
	std::string input;

	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Input must not be empty! Enter again:\n";
		input = get_input();
	}
	return input;
}

std::string PhoneBook::get_index()
{
	std::string index;

	std::getline(std::cin, index);
	if (index[0] > amount + '0' || index[0] < '1' || index[1] != '\0')
	{
		std::cout << "Wrong index. Try again.\n";
		index = get_index();
	}
	return index;
}

void PhoneBook::print_contact(int index)
{
	std::cout << std::endl;
	std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl; 
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl; 
	std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl; 
	std::cout << "Darkest Secret: " << contacts[index].get_secret() << std::endl; 
	std::cout << std::endl;
}

void PhoneBook::add_contact()
{
	Contact new_contact;
	std::string input;

	std::cout << "First Name:\n";
	input = get_input();
	new_contact.set_first_name(input);

	std::cout << "Last Name:\n";
	input = get_input();
	new_contact.set_last_name(input);

	std::cout << "Nickname:\n";
	input = get_input();
	new_contact.set_nickname(input);

	std::cout << "Phone Number:\n";
	input = get_input();
	new_contact.set_phone_number(input);

	std::cout << "Darkest Secret:\n";
	input = get_input();
	new_contact.set_secret(input);

	if (index == 8)
		index = 0;
	contacts[index++] = new_contact;

	if (amount != 8)
		amount++;
}

std::string PhoneBook::fit_string(std::string text)
{
	int text_len = text.length();

	if (text_len <= 10)
		return text;
	else
		return text.substr(0, 9) + ".";
}

void PhoneBook::search()
{
	std::string input;

	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].get_first_name() == "")
			continue;
		std::cout << std::right << std::setw(10) << i + 1 << " | ";
		std::cout << std::right << std::setw(10) << fit_string(contacts[i].get_first_name()) << " | ";
		std::cout << std::right << std::setw(10) << fit_string(contacts[i].get_last_name()) << " | ";
		std::cout << std::right << std::setw(10) << fit_string(contacts[i].get_nickname()) << std::endl;
	}
	std::cout << "\nNow choose the contact by the index: \n";
	input = get_index();
	print_contact(input[0] - '0' - 1);
	
}