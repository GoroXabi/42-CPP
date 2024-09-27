/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:21:55 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 11:23:34 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{

public:

	HumanB(std::string new_name);
	void	setWeapon(class Weapon &weapon);
	void	attack();

private:

	std::string name;
	Weapon *weapon;

};
#endif
