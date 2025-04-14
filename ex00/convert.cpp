/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:34:31 by paprzyby          #+#    #+#             */
/*   Updated: 2025/04/14 15:35:13 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	convertDouble(std::string string)
{
	std::string::iterator	str = string.begin();
	int						dots_count = 0;

	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (str != string.end())
	{
		if (*str == '.')
		{
			dots_count++;
		}
		else if (!std::isdigit(*str))
		{
			std::cerr << "This argument is not valid" << std::endl;
			return ;
		}
		str++;
	}
	if (dots_count != 1)
	{
		std::cerr << "This argument is not valid" << std::endl;
		return ;
	}
	try
	{
		double num = std::stod(string);
		if (isprint(num))
		{
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		}
		else
		{
			if (num < 0 || num > 255)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: " << "Non displayable" << std::endl;
		}
		if (num > INT_MAX)
		{
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(std::round(num * 10) / 10) << "f" << std::endl;
		std::cout << "double: " << std::round(num * 10) / 10 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "This argument is not valid" << std::endl;
	}
}

void	convertFloat(std::string string)
{
	std::string::iterator	str = string.begin();
	int						dots_count = 0;
	int						f_count = 0;

	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (str != string.end())
	{
		if (*str == '.')
		{
			dots_count++;
		}
		else if (*str == 'f')
		{
			f_count++;
		}
		else if (!std::isdigit(*str))
		{
			std::cerr << "This argument is not valid" << std::endl;
			return ;
		}
		str++;
	}
	if (dots_count != 1 || f_count != 1)
	{
		std::cerr << "This argument is not valid" << std::endl;
		return ;
	}
	try
	{
		float num = std::stof(string);

		if (isprint(num))
		{
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		}
		else
		{
			if (num < 0 || num > 255)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: " << "Non displayable" << std::endl;
		}
		if (num > INT_MAX)
		{
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << std::round(num * 10) / 10 << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(std::round(num * 10) / 10) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "This argument is not valid" << std::endl;
	}
}

void	convertInt(std::string string)
{
	std::string::iterator	str = string.begin();

	if (*str == '+' || *str == '-')
	{
		str++;
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
	try
	{
		int	num = std::stoi(string);

		if (isprint(num))
		{
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		}
		else
		{
			if (num < 0 || num > 255)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: " << "Non displayable" << std::endl;
		}
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "This argument is not valid" << std::endl;
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
	std::cout << "int: " << static_cast<int>(string[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(string[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(string[0]) << ".0" << std::endl;
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
	else if (literal.back() == 'f' && literal.find('.') != std::string::npos)
	{
		convertFloat(literal);
	}
	else if (literal.find(".") != std::string::npos)
	{
		convertDouble(literal);
	}
	else
	{
		convertInt(literal);
	}
}

//paprzyby@2-H-8 ex00 % ./convert 21423523.233f
//char: impossible
//int: 21423524
//float: 21423524.0f
//double: 21423524.0