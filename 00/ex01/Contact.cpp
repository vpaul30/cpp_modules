#include <string>
#include "Contact.hpp"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	secret = "";
}

void Contact::set_first_name(std::string param){ first_name = param; }
std::string Contact::get_first_name() { return first_name; }
void Contact::set_last_name(std::string param){ last_name = param; }
std::string Contact::get_last_name() { return last_name; }
void Contact::set_nickname(std::string param){ nickname = param; }
std::string Contact::get_nickname() { return nickname; }
void Contact::set_phone_number(std::string param){ phone_number = param; }
std::string Contact::get_phone_number() { return phone_number; }
void Contact::set_secret(std::string param){ secret = param; }
std::string Contact::get_secret() { return secret; }