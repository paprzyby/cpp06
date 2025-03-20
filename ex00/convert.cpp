/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:34:31 by paprzyby          #+#    #+#             */
/*   Updated: 2025/03/20 15:24:58 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//void	convertDouble(std::string string)
//{

//}

//void	convertFloat(std::string string)
//{

//}

//void	convertInt(std::string string)
//{

//}

void	convertChar(std::string string)
{
	std::cout << "char: " << string << std::endl;
	std::cerr << "int: " << static_cast<int>(string[0]) << std::endl;
	std::cerr << "float: " << static_cast<float>(string[0]) << ".0f" << std::endl;
	std::cerr << "double: " << static_cast<double>(string[0]) << ".0" << std::endl;
}

void ScalarConverter::convert(std::string const &literal)
{
	if (literal.empty())
	{
		std::cerr << "Empty string is not valid" << std::endl;
		return ;
	}
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		convertChar(literal);
	}
}
