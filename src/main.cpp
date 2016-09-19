/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/15 19:30:26 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "Factory.hpp"
#include "int8.hpp"
#include "TNumber.hpp"
#include <typeinfo>

int main()
{
	try
	{
		// IOperand const *a = new NumberType<int8_t>(static_cast<int8_t>(126));
		// IOperand const *b = new NumberType<int8_t>(static_cast<int8_t>(1));
		// IOperand const *a = new int8(126);
		// IOperand const *b = new int8(1);
	// int8 const *c;

	// eOperandType io;
	// (void)io;
	// io = eOperandType::Int8;

		Factory factory = Factory();
		(void)factory;
		std::cout << factory << std::endl;

		IOperand const *a = factory.createOperand(eOperandType::Int16, "32766");
		IOperand const *b = factory.createOperand(eOperandType::Int16, "2");
		IOperand const *c;
		IOperand const *d = factory.createOperand(eOperandType::Int16, "120");
		(void)d;
		std::cout << "Test1: " << d << std::endl;

	// createOperand = createOperand();



	// IOperand const *d = createOperand::createInt8("lol");
	// (void)d;
		// std::cout << "Test1: " << d << std::endl;

		std::cout << static_cast<int>(eOperandType::Int8) << std::endl;
		std::cout << static_cast<int>(eOperandType::Int16) << std::endl;
		std::cout << static_cast<int>(eOperandType::Int32) << std::endl;
		std::cout << static_cast<int>(eOperandType::Float) << std::endl;
		std::cout << static_cast<int>(eOperandType::Double) << std::endl;

		(void)a;
		(void)b;
		(void)c;

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

////////////////////////////////////////////////////////////////////////

	// IOperand const *e;
	// NumberType<int> cr;

	// uint16_t val = 15;
	// uint16_t ret = cr.create(val);

	// std::cout << val << std::endl;
	// std::cout << ret << std::endl;
	uint8_t k;
	std::cout << typeid(k).name() << std::endl;
		uint16_t l;
	std::cout << typeid(l).name() << std::endl;
		uint32_t m;
	std::cout << typeid(m).name() << std::endl;
		float n;
	std::cout << typeid(n).name() << std::endl;
		double o;
	std::cout << typeid(o).name() << std::endl;

	return (0);
}
