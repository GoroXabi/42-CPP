/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:10:23 by xabier            #+#    #+#             */
/*   Updated: 2024/09/24 11:40:06 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

class	PhoneBook
{

public:

	PhoneBook();
	~PhoneBook();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	Contact	get_contact(int i);
	void	add_contact(int i);
	void	search(void);
	int		count_added_contacts();

private:

	Contact contacts[8];

};

#endif