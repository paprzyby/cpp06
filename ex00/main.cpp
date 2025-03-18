/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:18:14 by paprzyby          #+#    #+#             */
/*   Updated: 2025/03/18 16:36:07 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Too few arguments passed." << std::endl;
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	else if (ac == 2)
	{
		ScalarConverter converter;

		converter.convert(av[1]);
		return (0);
	}
	else
	{
		std::cerr << "Too many arguments passed." << std::endl;
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
}
