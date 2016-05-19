/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/19 19:16:24 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "int8.hpp"

int main()
{
	int8 a(4);
	int8 b(3);
	int8 c;

	c = a + b;
	std::cout << c << std::endl;

	c = a - b;
	std::cout << c << std::endl;

	c = a * b;
	std::cout << c << std::endl;

	c = a / b;
	std::cout << c << std::endl;

	c = a % b;
	std::cout << c << std::endl;
	return (0);
}
