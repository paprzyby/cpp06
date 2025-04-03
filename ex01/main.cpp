/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:43:48 by paprzyby          #+#    #+#             */
/*   Updated: 2025/04/03 17:15:34 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data data;

	data.str = "Hello";
	std::cout << "Original Data object: " << data.str << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized Data object: " << deserialized->str << std::endl;
	if (deserialized == &data)
	{
		std::cout << "Pointers match!" << std::endl;
	}
	else
	{
		std::cout << "Pointers don't match!" << std::endl;
	}
}
