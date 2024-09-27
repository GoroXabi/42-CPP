/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:01 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 12:06:10 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string new_type){
	type = new_type;
}

const std::string	&Weapon::getType(){
	return (type);
}

void	Weapon::setType(std::string new_type){
	type = new_type;
}
