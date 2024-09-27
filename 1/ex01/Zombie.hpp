/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:01:55 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 11:04:36 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	
public:

	Zombie();
	Zombie(std::string new_name);
	~Zombie();

	void	set_name(std::string name);
	void	announce(void);

private:

	std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
