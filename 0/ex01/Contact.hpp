/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:57:14 by xabier            #+#    #+#             */
/*   Updated: 2024/09/24 11:41:45 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class	Contact
{
	
public:

	Contact();
	~Contact();

/*----------------------GETTERS----------------------*/

	void			set_first_name(std::string new_first_name);
	void			set_last_name(std::string new_last_name);
	void			set_nick_name(std::string new_nick_name);
	void			set_phone_number(std::string phone_number);
	void			set_dark_secret(std::string dark_secret);

/*----------------------SETTERS----------------------*/

	std::string		get_first_name(void);
	std::string		get_last_name(void);
	std::string		get_nick_name(void);
	std::string		get_phone_number(void);
	std::string		get_dark_secret(void);

private:

	std::string		first_name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string		dark_secret;

};

#endif
