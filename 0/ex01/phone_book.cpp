
#include "phone_book.hpp"
#include "contact.hpp"
#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

Phone_Book::Phone_Book()
{
}

Contact	Phone_Book::get_contact(int i){
	return (contacts[i]);
}

int		Phone_Book::count_added_contacts()
{
	int n;

	for (n = 0; n < 8; n++) {
		if (contacts[n].get_first_name() == "")
			break;
	}
	return (n);
}

void	Phone_Book::add_contact(int i)
{
	std::string	buffer;

	std::cout << "First Name:" << std::endl;
	std::getline(std::cin, buffer);
	while (buffer.empty() || buffer == "\n"){
		std::cout << "Not a valid imput" << std::endl;
		std::getline(std::cin, buffer);
	}
	contacts[i].set_first_name(buffer);

	std::cout << "Last Name:" << std::endl;
	std::getline(std::cin, buffer);
	while (buffer.empty() || buffer == "\n"){
		std::cout << "Not a valid imput" << std::endl;
		std::getline(std::cin, buffer);
	}
	contacts[i].set_last_name(buffer);

	std::cout << "Nick Name:" << std::endl;
	std::getline(std::cin, buffer);
	while (buffer.empty() || buffer == "\n"){
		std::cout << "Not a valid imput" << std::endl;
		std::getline(std::cin, buffer);
	}
	contacts[i].set_nick_name(buffer);

	std::cout << "Phone Number:" << std::endl;
	std::getline(std::cin, buffer);
	while (buffer.empty() || buffer == "\n"){
		std::cout << "Not a valid imput" << std::endl;
		std::getline(std::cin, buffer);
	}
	contacts[i].set_phone_number(buffer);

	std::cout << "Dark Secret:" << std::endl;
	std::getline(std::cin, buffer);
	while (buffer.empty() || buffer == "\n"){
		std::cout << "Not a valid imput" << std::endl;
		std::getline(std::cin, buffer);
	}
	contacts[i].set_dark_secret(buffer);
}

void	print_col(std::string str)
{
	if (str.length() > 10)
		std::cout << "|" << str.substr(0, 9) << ".";
	else 
		std::cout << "|" << std::setw(10) << std::right << str;
}

void	Phone_Book::search(void)
{
	int	n;
	std::string	prompt;
	if (count_added_contacts() == 0){

		std::cout << "NO CONTACTS ADDED" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     INDEX|FIRST_NAME|SECOND_NA.| NICK_NAME|" << std::endl;
	for (n = 0; n < count_added_contacts(); n++) {
			std::cout << "---------------------------------------------" << std::endl;
			std::string number(1, n + 48);
			print_col(number);
			print_col(contacts[n].get_first_name());
			print_col(contacts[n].get_last_name());
			print_col(contacts[n].get_nick_name());
			std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "WHAT CONTACT DO YOU WANT TO SEE?" << std::endl;
	std::cout << "PLEASE INSERT THE INDEX" << std::endl;
	while (true) {
		std::getline(std::cin, prompt);
		for (n = 0; n < count_added_contacts(); n++) {
			if (prompt.length() == 1 && prompt[0] - 48 == n)
			{
				std::cout << "FIRST NAME: " << contacts[n].get_first_name() << std::endl;
				std::cout << "SECOND NAME: " << contacts[n].get_last_name() << std::endl;
				std::cout << "NICK NAME: " << contacts[n].get_nick_name() << std::endl;
				std::cout << "PHONE NUMBER: " << contacts[n].get_phone_number() << std::endl;
				std::cout << "DARK SECRET: " << contacts[n].get_dark_secret() << std::endl;
				return ;
			}
		}
		std::cout << "PLEASE INSERT A CORRECT INDEX" << std::endl;
	}
}