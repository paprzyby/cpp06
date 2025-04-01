/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:34:31 by paprzyby          #+#    #+#             */
/*   Updated: 2025/04/01 15:34:40 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//void	convertDouble(std::string string)
//{

//}

//void	convertFloat(std::string string)
//{
//	bool					minus_flag = false;
//	std::string::iterator	str;

//	if (string[0] == '-' || string[0] == '+')
//	{
//		if (string[0] == '-')
//			minus_flag = true;
//		str = string.begin() + 1;
//	}
//	else
//	{
//		str = string.begin();
//	}
//}

void	convertInt(std::string string)
{
	std::string::iterator	str;

	str = string.begin();
	if (*str == '+' || *str == '-')
	{
		str++;
		std::cerr << "+ or -" << std::endl;
		return ;
	}
	while (str != string.end())
	{
		if (!std::isdigit(*str))
		{
			std::cerr << "This argument is not valid" << std::endl;
			return ;
		}
		str++;
	}
}

void	convertPseudo(std::string string)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (string == "nan" || string == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (string == "+inf" || string == "+inff" || string == "inf" || string == "inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	convertChar(std::string string)
{
	std::cout << "char: '" << string << "'" << std::endl;
	std::cerr << "int: " << static_cast<int>(string[0]) << std::endl;
	std::cerr << "float: " << static_cast<float>(string[0]) << ".0f" << std::endl;
	std::cerr << "double: " << static_cast<double>(string[0]) << ".0" << std::endl;
}

void ScalarConverter::convert(std::string const &literal)
{
	if (literal.empty())
	{
		std::cerr << "Empty string is not valid" << std::endl;
	}
	else if (literal == "nan" || literal == "nanf" ||
		literal == "+inf" || literal == "+inff" ||
		literal == "-inf" || literal == "-inff" ||
		literal == "inf" || literal == "inff")
	{
		convertPseudo(literal);
	}
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		convertChar(literal);
	}
	else if (literal.find("f") != std::string::npos)
	{
		std::cout << "float" << std::endl;
	}
	else if (literal.find(".") != std::string::npos)
	{
		std::cout << "double" << std::endl;
	}
	else
	{
		convertInt(literal);
	}
}
