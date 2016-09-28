/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/28 13:23:30 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "Factory.hpp"
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

		IOperand const *a = factory.createOperand(eOperandType::Int16, "32760");
		IOperand const *b = factory.createOperand(eOperandType::Int16, "2");
		IOperand const *c;
		IOperand const *d = factory.createOperand(eOperandType::Int16, "120");
		(void)d;
		std::cout << "Test1: " << d << std::endl;

	// createOperand = createOperand();



	// IOperand const *d = createOperand::createInt8("lol");
	// (void)d;
		// std::cout << "Test1: " << d << std::endl;

		std::cout << "int8	:" << static_cast<int>(eOperandType::Int8) << std::endl;
		std::cout << "int16	:" << static_cast<int>(eOperandType::Int16) << std::endl;
		std::cout << "int32	:" << static_cast<int>(eOperandType::Int32) << std::endl;
		std::cout << "float	:" << static_cast<int>(eOperandType::Float) << std::endl;
		std::cout << "double	:" << static_cast<int>(eOperandType::Double) << std::endl;

		std::cout << "TestPres: " << a->getPrecision() << std::endl;

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
	int8_t k;
	std::cout << "int8	:" << typeid(k).name() << std::endl;
	int16_t l;
	std::cout << "int16	:" << typeid(l).name() << std::endl;
	int32_t m;
	std::cout << "int32	:" << typeid(m).name() << std::endl;
	float n;
	std::cout << "float	:" << typeid(n).name() << std::endl;
	double o;
	std::cout << "double	:" << typeid(o).name() << std::endl;

	return (0);
}
