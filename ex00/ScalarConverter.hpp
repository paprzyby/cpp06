/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:21:14 by paprzyby          #+#    #+#             */
/*   Updated: 2025/04/01 15:53:49 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <climits>

class	ScalarConverter
{
	public:
		static void convert(std::string const &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
};

void	convertChar(std::string string);
void	convertInt(std::string string);
void	convertFloat(std::string string);
void	convertDouble(std::string string);
void	convertPseudo(std::string string);

#endif
