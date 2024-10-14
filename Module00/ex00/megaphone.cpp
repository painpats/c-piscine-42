/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:53:11 by cbourre           #+#    #+#             */
/*   Updated: 2023/10/27 18:53:16 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int arg=1 ; arg < ac ; arg++)
	{
		std::string str = av[arg];
		std::string::size_type len = str.length();
		for (std::string::size_type i=0 ; i < len ; ++i)
			std::cout << (char)(std::toupper(str[i]));
	}
	std::cout << std::endl;
	return (0);
}
