/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabier <xabier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:10:23 by xabier            #+#    #+#             */
/*   Updated: 2024/06/20 17:44:49 by xabier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "contact.hpp"
#include <iomanip>
#include <string>

class	Phone_Book
{
private:
	Contact contacts[8];
public:
	Phone_Book();
	Contact	get_contact(int i);
	void	add_contact(int i);
	void	search(void);
	int		count_added_contacts();
};

#endif