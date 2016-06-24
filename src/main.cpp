/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/06/24 18:39:35 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "int8.hpp"

int main()
{
	int8 *a = new int8(4);
	int8 *b = new int8(3);
	int8 c;

	(void)a;
	(void)b;
	(void)c;

	// std::string *str = new std::string("Hello");
	// (void)str;	

	// std::string *str2 = new std::string("HI THIS IS BRAIN");
	// std::string &strref2 = *str2;
	// (void)str2;	
	// (void)strref2;	

	// std::string str = "HI THIS IS BRAIN";
	// std::string *strptr = &str;
	// std::string &strref = str;

	// std::cout << str << std::endl;
	// std::cout << *strptr << std::endl;
	// std::cout << strref << std::endl;

 
	// std::cout << *a << std::endl;

	c = *a + *b;
	// c = a + b;
	std::cout << c << std::endl;

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
