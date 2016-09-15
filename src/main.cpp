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

	IOperand const *a = new int8(126);
	IOperand const *b = new int8(1);
	IOperand const *c;
	// int8 const *c;

	enum class eOperandType {Int8, Int16, Int32, Float, Double};

	eOperandType io;
	(void)io;

	io = eOperandType::Int8;

	std::cout << static_cast<int>(eOperandType::Int8) << std::endl;
	std::cout << static_cast<int>(eOperandType::Int16) << std::endl;
	std::cout << static_cast<int>(eOperandType::Int32) << std::endl;
	std::cout << static_cast<int>(eOperandType::Float) << std::endl;
	std::cout << static_cast<int>(eOperandType::Double) << std::endl;

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
