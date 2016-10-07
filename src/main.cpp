/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/07 21:15:30 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "Factory.hpp"
#include "TNumber.hpp"
#include "Stack.hpp"
#include "Parse.hpp"


// #include <sstream>

// void ft_add(eOperandType ioone, eOperandType iotwo, std::string vone, std::string vtwo)
// {
// 	try
// 	{
// 		Factory factory = Factory();
// 		std::cout.precision(10);

// 		IOperand const *res;

// 		IOperand const *one = factory.createOperand(ioone, vone);
// 		IOperand const *two = factory.createOperand(iotwo, vtwo);
// 		std::cout << "Precision: "<< one->getPrecision() << " | " << one->toString() << " + " << two->toString() << " = ";
// 		res = *one + *two;
// 		std::cout << res->toString();

// 		long double a = std::strtold(vone.c_str(), NULL);
// 		long double b = std::strtold(vtwo.c_str(), NULL);
// 		// double a = std::stod(vone);
// 		// double b = std::stod(vtwo);
// 		long double c = a + b;
// 		long double d = std::strtold(res->toString().c_str(), NULL);
// 		if (c == d)
// 			std::cout << " OK ";
// 		else
// 			std::cout << " Check ";

// 		std::cout << std::endl;

// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

// void ft_sub(eOperandType ioone, eOperandType iotwo, std::string vone, std::string vtwo)
// {
// 	try
// 	{
// 		Factory factory = Factory();

// 		IOperand const *res;

// 		IOperand const *one = factory.createOperand(ioone, vone);
// 		IOperand const *two = factory.createOperand(iotwo, vtwo);
// 		std::cout << "Precision: "<< one->getPrecision() << " | " << one->toString() << " - " << two->toString() << " = ";
// 		res = *one - *two;
// 		std::cout << res->toString();

// 		double a = std::stod(vone);
// 		double b = std::stod(vtwo);
// 		double c = a - b;
// 		double d = std::stod(res->toString());
// 		if (c == d)
// 			std::cout << " OK ";
// 		else
// 			std::cout << " Check ";

// 		std::cout << std::endl;

// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

// void ft_div(eOperandType ioone, eOperandType iotwo, std::string vone, std::string vtwo)
// {
// 	try
// 	{
// 		Factory factory = Factory();

// 		IOperand const *res;

// 		IOperand const *one = factory.createOperand(ioone, vone);
// 		IOperand const *two = factory.createOperand(iotwo, vtwo);
// 		std::cout << "Precision: "<< one->getPrecision() << " | " << one->toString() << " / " << two->toString() << " = ";
// 		res = *one / *two;
// 		std::cout << res->toString();

// 		double a = std::stod(vone);
// 		double b = std::stod(vtwo);
// 		double c = a / b;
// 		double d = std::stod(res->toString());
// 		if (c == d)
// 			std::cout << " OK ";
// 		else
// 			std::cout << " Check ";

// 		std::cout << std::endl;

// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

// void ft_test_add()
// {
// 	float maxf = std::numeric_limits<float>::max();
// 	float minf = std::numeric_limits<float>::lowest();
// 	double maxd = std::numeric_limits<double>::max();
// 	double mind = std::numeric_limits<double>::lowest();
// 	(void)maxf;
// 	(void)minf;
// 	(void)maxd;
// 	(void)mind;

// 	try
// 	{
// 		// std::setprecision(10);
// 		std::cout << "ADD" << std::endl;
// 		std::cout << "--------------" << std::endl;
// 		ft_add(eOperandType::Int8, eOperandType::Int8, "120", "7");
// 		ft_add(eOperandType::Int8, eOperandType::Int8, "120", "8");
// 		ft_add(eOperandType::Int8, eOperandType::Int8, "-120", "-8");
// 		ft_add(eOperandType::Int8, eOperandType::Int8, "-120", "-9");
// 		std::cout << "--------------" << std::endl;
// 		ft_add(eOperandType::Int16, eOperandType::Int8, "32760", "7");
// 		ft_add(eOperandType::Int16, eOperandType::Int8, "32760", "8");
// 		ft_add(eOperandType::Int16, eOperandType::Int8, "-32760", "-8");
// 		ft_add(eOperandType::Int16, eOperandType::Int8, "-32760", "-9");
// 		std::cout << "--------------" << std::endl;
// 		ft_add(eOperandType::Int32, eOperandType::Int8, "2147483646", "1");
// 		ft_add(eOperandType::Int32, eOperandType::Int8, "2147483647", "1");
// 		ft_add(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-1");
// 		ft_add(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-3");
// 		std::cout << "--------------" << std::endl;
// 		ft_add(eOperandType::Float, eOperandType::Float, "1.1234", "2.1234");
// 		ft_add(eOperandType::Float, eOperandType::Float, std::to_string(maxf), std::to_string(maxf));
// 		ft_add(eOperandType::Float, eOperandType::Float, "-1.1234", "-2.1234");
// 		ft_add(eOperandType::Float, eOperandType::Float, std::to_string(minf), std::to_string(minf));
// 		std::cout << "--------------" << std::endl;
// 		ft_add(eOperandType::Double, eOperandType::Double, "555555555.1111122222", "2.1111122222");
// 		ft_add(eOperandType::Double, eOperandType::Double, std::to_string(maxd), std::to_string(maxd));
// 		ft_add(eOperandType::Double, eOperandType::Double, "-55555555.1111122222", "-2.1111122222");
// 		ft_add(eOperandType::Double, eOperandType::Double, std::to_string(mind), std::to_string(mind));
		
// 		std::cout << "SUB" << std::endl;
// 		std::cout << "--------------" << std::endl;
// 		ft_sub(eOperandType::Int8, eOperandType::Int8, "-126", "2");
// 		ft_sub(eOperandType::Int8, eOperandType::Int8, "-126", "3");
// 		ft_sub(eOperandType::Int8, eOperandType::Int8, "126", "-1");
// 		ft_sub(eOperandType::Int8, eOperandType::Int8, "126", "-2");
// 		std::cout << "--------------" << std::endl;
// 		ft_sub(eOperandType::Int16, eOperandType::Int8, "-32766", "1");
// 		ft_sub(eOperandType::Int16, eOperandType::Int8, "-32767", "2");
// 		ft_sub(eOperandType::Int16, eOperandType::Int8, "32766", "-1");
// 		ft_sub(eOperandType::Int16, eOperandType::Int8, "32766", "-2");
// 		// std::cout << "--------------" << std::endl;
// 		// ft_sub(eOperandType::Int32, eOperandType::Int8, "2147483646", "1");
// 		// ft_sub(eOperandType::Int32, eOperandType::Int8, "2147483647", "1");
// 		// ft_sub(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-1");
// 		// ft_sub(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-3");
// 		// std::cout << "--------------" << std::endl;
// 		// ft_sub(eOperandType::Float, eOperandType::Float, "55555.1234", "2.1234");
// 		// ft_sub(eOperandType::Float, eOperandType::Float, "340282001837565597733306976381245063168", "-111111");
// 		// std::cout << "--------------" << std::endl;
// 		// ft_sub(eOperandType::Double, eOperandType::Double, "350.123456", "1");
// 		// ft_sub(eOperandType::Double, eOperandType::Int8, "350.123456", "1");
// 		std::cout << "--------------" << std::endl;
// 		std::cout << "DIV" << std::endl;
// 		std::cout << "--------------" << std::endl;
// 		ft_div(eOperandType::Double, eOperandType::Int8, "10", "2");
// 		ft_div(eOperandType::Double, eOperandType::Int8, "-10", "2");
// 		ft_div(eOperandType::Double, eOperandType::Int8, "10", "0");
// 		ft_div(eOperandType::Double, eOperandType::Int8, "10", "5");
// 		ft_div(eOperandType::Double, eOperandType::Int8, "0", "0");
// 				std::cout << "--------------" << std::endl;
// 		ft_div(eOperandType::Int8, eOperandType::Int8, "120", "7");
// 		ft_div(eOperandType::Int8, eOperandType::Int8, "120", "8");
// 		ft_div(eOperandType::Int8, eOperandType::Int8, "-120", "-8");
// 		ft_div(eOperandType::Int8, eOperandType::Int8, "-120", "-9");
// 		std::cout << "--------------" << std::endl;
// 		ft_div(eOperandType::Int16, eOperandType::Int8, "32760", "7");
// 		ft_div(eOperandType::Int16, eOperandType::Int8, "32760", "8");
// 		ft_div(eOperandType::Int16, eOperandType::Int8, "-32760", "-8");
// 		ft_div(eOperandType::Int16, eOperandType::Int8, "-32760", "-9");
// 		std::cout << "--------------" << std::endl;
// 		ft_div(eOperandType::Int32, eOperandType::Int8, "2147483646", "1");
// 		ft_div(eOperandType::Int32, eOperandType::Int8, "2147483647", "1");
// 		ft_div(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-1");
// 		ft_div(eOperandType::Int32, eOperandType::Int8, "-2147483646", "-3");
// 		std::cout << "--------------" << std::endl;
// 		ft_div(eOperandType::Float, eOperandType::Float, "1.1234", "2.1234");
// 		ft_div(eOperandType::Float, eOperandType::Float, std::to_string(maxf), std::to_string(maxf));
// 		ft_div(eOperandType::Float, eOperandType::Float, "-1.1234", "-2.1234");
// 		ft_div(eOperandType::Float, eOperandType::Float, std::to_string(minf), std::to_string(minf));
// 		std::cout << "--------------" << std::endl;
// 		ft_div(eOperandType::Double, eOperandType::Double, "555555555.1111122222", "2.1111122222");
// 		ft_div(eOperandType::Double, eOperandType::Double, std::to_string(maxd), std::to_string(maxd));
// 		ft_div(eOperandType::Double, eOperandType::Double, "-55555555.1111122222", "-2.1111122222");
// 		ft_div(eOperandType::Double, eOperandType::Double, std::to_string(mind), std::to_string(mind));
		


// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

int main(int ac, char**av)
{
	(void)ac;
	(void)av;

	try
	{
		Stack *s = new Stack();
		Parse p = Parse(s);

		if (ac > 1)
		{
			std::string file = av[1];
			p.openFile(file);
			p.readFile();
		}
		else
			p.readFromUser();
		s->checkExit();
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}

	return (0);
}
