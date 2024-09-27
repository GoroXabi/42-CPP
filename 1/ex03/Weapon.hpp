/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:04 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 12:06:02 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{

public:

	Weapon();
	Weapon(std::string new_type);
	const std::string	&getType();
	void				setType(std::string new_type);

private:

	std::string type;

};

#endif
