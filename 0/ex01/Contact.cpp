#include "Contact.hpp"
#include <string>

Contact::Contact()
{
    first_name = "";
    last_name = "";
    nick_name = "";
    phone_number = "";
    dark_secret = "";
}

void	Contact::set_first_name(std::string new_first_name){
	first_name = new_first_name;
}

std::string Contact::get_first_name(void){
	return (first_name);
}

void	Contact::set_last_name(std::string new_last_name){
	last_name = new_last_name;
}

std::string Contact::get_last_name(void){
	return (last_name);
}

void	Contact::set_nick_name(std::string new_nick_name){
	nick_name = new_nick_name;
}

std::string Contact::get_nick_name(void){
	return (nick_name);
}

std::string Contact::get_phone_number(void){
	return (phone_number);
}

void	Contact::set_phone_number(std::string new_phone_number){
	phone_number = new_phone_number;
}

std::string Contact::get_dark_secret(void){
	return (dark_secret);
}

void	Contact::set_dark_secret(std::string new_dark_secret){
	dark_secret = new_dark_secret;
}
