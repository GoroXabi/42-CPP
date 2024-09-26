/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:09:34 by xortega           #+#    #+#             */
/*   Updated: 2024/09/24 11:23:47 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook	book;
	std::string prompt;
	int			n = 0;
	
	std::cout << "PHONE BOOK" << std::endl;

	std::cout << "TYPE ADD TO ADD A NEW CONTACT" << std::endl;

	std::cout << "TYPE SEARCH TO VIEW AND SEARCH FOR AN EXISTING CONTACT" << std::endl;

	std::cout << "TYPE EXIT TO EXIT, ALL CONTACT WHILL BE LOST" << std::endl;


	while (true)
	{
		std::cout << "PLEASE ENTER A COMMAND" << std::endl;
		std::getline(std::cin, prompt);
		while (prompt != "ADD" && prompt != "SEARCH" && prompt != "EXIT")
		{
			std::cout << "NOT A VALID COMMAND SOWRY" << std::endl;
			std::getline(std::cin, prompt);
		}
		if (prompt == "ADD")
		{
			if (n == 8)
				n = 0;
			book.add_contact(n);
			n++;
		std::cout << "CONTACT ADDED!" << std::endl;
		}
		if (prompt == "SEARCH")
			book.search();
		if (prompt == "EXIT")
			return (0);
	}
}