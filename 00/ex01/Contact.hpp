#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
	Contact();
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
	public:
		void set_first_name(std::string param);
		std::string get_first_name();
		void set_last_name(std::string param);
		std::string get_last_name();
		void set_nickname(std::string param); 
		std::string get_nickname();
		void set_phone_number(std::string param); 
		std::string get_phone_number();
		void set_secret(std::string param); 
		std::string get_secret();
};

#endif