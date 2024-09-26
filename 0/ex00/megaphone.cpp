/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:30:59 by xabier            #+#    #+#             */
/*   Updated: 2024/09/24 11:11:02 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main(int argc, char **argv)
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
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
