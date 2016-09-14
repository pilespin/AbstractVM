/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/14 15:26:19 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "int8.hpp"

int main()
{

	IOperand const *a = new int8(127);
	IOperand const *b = new int8(1);
	IOperand const *c;
	// int8 const *c;

	(void)a;
	(void)b;
	(void)c;

	try
	{

		c = *a + *b;
	// c = a + b;
	// std::cout << reinterpret_cast<int8*>(c)->getValue() << std::endl;
		std::cout << c << std::endl;
		std::cout << c->toString() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
