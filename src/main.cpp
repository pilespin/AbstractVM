/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/03 19:15:41 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "Factory.hpp"
#include "TNumber.hpp"
#include "Stack.hpp"
#include "Parse.hpp"
#include <sstream>



void ft_add(eOperandType ioone, eOperandType iotwo, std::string vone, std::string vtwo)
{
	try
	{
		Factory factory = Factory();

		IOperand const *res;

		IOperand const *one = factory.createOperand(ioone, vone);
		IOperand const *two = factory.createOperand(iotwo, vtwo);
		std::cout << "Precision: "<< one->getPrecision() << " | " << one->toString() << " + " << two->toString() << " = ";
		res = *one + *two;
		std::cout << res->toString();

		double a = std::stof(vone);
		double b = std::stof(vtwo);
		double c = a + b;
		double d = std::stof(res->toString());
		if (c == d)
			std::cout << " OK ";
		else
			std::cout << " Check ";

		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ft_div(eOperandType ioone, eOperandType iotwo, std::string vone, std::string vtwo)
{
	try
	{
		Factory factory = Factory();

		IOperand const *res;

		IOperand const *one = factory.createOperand(ioone, vone);
		IOperand const *two = factory.createOperand(iotwo, vtwo);
		std::cout << "Precision: "<< one->getPrecision() << " | " << one->toString() << " / " << two->toString() << " = ";
		res = *one / *two;
		std::cout << res->toString();

		double a = std::stof(vone);
		double b = std::stof(vtwo);
		double c = a / b;
		double d = std::stof(res->toString());
		if (c == d)
			std::cout << " OK ";
		else
			std::cout << " Check ";

		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ft_test_add()
{
	try
	{
		std::cout << "ADD" << std::endl;
		std::cout << "--------------" << std::endl;
		ft_add(eOperandType::Int8, eOperandType::Int8, "120", "7");
		ft_add(eOperandType::Int8, eOperandType::Int8, "120", "8");
		ft_add(eOperandType::Int8, eOperandType::Int8, "-120", "-8");
		ft_add(eOperandType::Int8, eOperandType::Int8, "-120", "-9");
		std::cout << "--------------" << std::endl;
		ft_add(eOperandType::Int16, eOperandType::Int8, "32760", "7");
		ft_add(eOperandType::Int16, eOperandType::Int8, "32760", "8");
		ft_add(eOperandType::Int16, eOperandType::Int8, "-32760", "-8");
		ft_add(eOperandType::Int16, eOperandType::Int8, "-32760", "-9");
		std::cout << "--------------" << std::endl;
		ft_add(eOperandType::Int32, eOperandType::Int8, "2147483646", "1");
		ft_add(eOperandType::Int32, eOperandType::Int8, "2147483647", "1");
		ft_add(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-1");
		ft_add(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-3");
		std::cout << "--------------" << std::endl;
		ft_add(eOperandType::Float, eOperandType::Float, "55555.1234", "2.1234");
		ft_add(eOperandType::Float, eOperandType::Float, "340282001837565597733306976381245063168", "-111111");
		std::cout << "--------------" << std::endl;
		ft_add(eOperandType::Double, eOperandType::Double, "350.123456", "1");
		ft_add(eOperandType::Double, eOperandType::Int8, "350.123456", "1");
		std::cout << "DIV" << std::endl;
		std::cout << "--------------" << std::endl;
		ft_div(eOperandType::Double, eOperandType::Int8, "10", "2");
		ft_div(eOperandType::Double, eOperandType::Int8, "-10", "2");
		ft_div(eOperandType::Double, eOperandType::Int8, "10", "0");

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{

	try
	{
		// ft_test_add();

		Stack *s = new Stack();
		Parse p = Parse(s);

		(void)s;

		Factory factory = Factory();
		IOperand const *one = factory.createOperand(eOperandType::Double, "50");
		IOperand const *two = factory.createOperand(eOperandType::Int8, "90");

		(void)one;
		(void)two;
		// s.push(one);
		// s.push(two);

		// s.dump();
		// s.assert("+90.0000");

		// // s.pop();
		// // s.pop();
		// s.dump();
		// s.operate(eOperatorType::Mul);
		// s.push(two);
		// s.push(two);
		// s.push(two);
		// s.push(two);
		// s.dump();
		// s.print();
		// s.print();
		// s.print();
		// s.print();

		s->push(two);
		s->push(two);

		// std::ifstream file;
		// file.open("sampl");
		// if (file.is_open())
		// {
		// 	std::cout << "Unable to open file: " << std::endl;
		// }

		p.openFile("sample");
		p.readFile();


	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}

	return (0);
}
