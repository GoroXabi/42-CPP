/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabier <xabier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:57:14 by xabier            #+#    #+#             */
/*   Updated: 2024/06/18 17:44:49 by xabier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class   Contact
{
private:

	std::string first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	dark_secret;

public:

	Contact();

	std::string get_first_name(void);
	void	set_first_name(std::string new_first_name);

	void	set_last_name(std::string new_last_name);
	std::string get_last_name(void);

	void	set_nick_name(std::string new_nick_name);
	std::string get_nick_name(void);

	void	set_phone_number(std::string phone_number);
	std::string get_phone_number(void);

	void	set_dark_secret(std::string dark_secret);
	std::string get_dark_secret(void);
};

#endif