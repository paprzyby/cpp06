/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:17:43 by paprzyby          #+#    #+#             */
/*   Updated: 2025/04/03 17:47:54 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate()
{
	int randomValue = rand() % 100;

	if (randomValue < 25)
		return (new (A));
	else if (randomValue < 50)
		return (new (B));
	else
		return (new (C));
}

//void	identify(Base *p)
//{

//}

//void	identify(Base &p)
//{

//}

int	main()
{
	srand(time(NULL));

	Base	*base;

	base = generate();
	return (0);
}
