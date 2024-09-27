/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:49:57 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 11:08:04 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main() {

	int N = 5;
	int i;
	Zombie *Horde = zombieHorde(N, "Legion");

	for (i = 0; i < N; i++) {
		Horde[i].announce();
	}
	
	delete[] Horde;
    
	return (0);
}
