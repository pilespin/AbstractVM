/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/20 21:06:04 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "int8.hpp"

int main()
{
	int8 *a = new int8(4);
	int8 *b = new int8(3);
	int8 *c;

	(void)a;
	(void)b;
	(void)c;

	std::string *str = new std::string("Hello");
	(void)str;


	// int8 a(4);
	// int8 b(3);
	// int8 c;
	std::cout << *a << std::endl;

	// c = *a + *b;   
	// std::cout << *c << std::endl;

	// c = a - b;
	// std::cout << c << std::endl;

	// c = a * b;
	// std::cout << c << std::endl;

	// c = a / b;
	// std::cout << c << std::endl;

	// c = a % b;
	// std::cout << c << std::endl;
	return (0);
}
