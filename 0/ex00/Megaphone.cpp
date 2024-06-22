/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabier <xabier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:30:59 by xabier            #+#    #+#             */
/*   Updated: 2024/06/18 17:11:42 by xabier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int    main(int argc, char **argv)
{
	int 	i;
	size_t	k;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for(k = 0; k < str.size(); k++)
				std::cout << (char)std::toupper(str[k]);
		}
	}
	else
		std::cout << "...";
	std::cout << std::endl;
	return (0);
}
