/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:22:23 by paprzyby          #+#    #+#             */
/*   Updated: 2025/03/18 16:35:40 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()	{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()	{}

void ScalarConverter::convert(std::string const &literal)
{

}
