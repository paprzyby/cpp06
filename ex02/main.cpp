/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:17:43 by paprzyby          #+#    #+#             */
/*   Updated: 2025/04/03 18:27:54 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base	*generate()
{
	std::random_device				device;
	std::mt19937					generate(device());
	std::uniform_int_distribution	range(1, 3);
	int								random = range(generate);

	if (random == 1)
		return (new A);
	else if (random == 2)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cerr << "NULL" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int	main()
{
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);
	return (0);
}
