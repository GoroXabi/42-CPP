/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:35:32 by xortega           #+#    #+#             */
/*   Updated: 2024/09/26 10:44:53 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

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

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
