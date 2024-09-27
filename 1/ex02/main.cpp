/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:13:58 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 11:20:47 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string addres\t\t = \t" << &string << std::endl;
	std::cout << "stringPTR addres\t = \t" << stringPTR << std::endl;
	std::cout << "stringREF addres\t = \t" << &stringREF << std::endl;

	std::cout << "string content\t\t = \t" << string << std::endl;
	std::cout << "stringPTR content\t = \t" << *stringPTR << std::endl;
	std::cout << "stringREF content\t = \t" << stringREF << std::endl;

    return (0);
}
