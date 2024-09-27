/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:32:15 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 10:39:00 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main() {

	Zombie *Jaime = newZombie("Jaime");
	randomChump("Luis");
	Jaime->announce();
	delete Jaime;
    return (0);
}
