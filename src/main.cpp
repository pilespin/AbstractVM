/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/30 18:26:11 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "Factory.hpp"
#include "TNumber.hpp"
#include <sstream>

#include <cmath>
#include <ctgmath>

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
		std::cout << res->toString() << std::endl;
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

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	ft_test_add();

	// float fl = std::numeric_limits<float>::max();

	// std::cout << "float: " << fl << std::endl;

	// float fl2 = 100000085555550.121121345;

	// std::cout << "float: " << fl2 << std::endl;

	// float fl3;

	// fl3 = fl + fl2;
	// fl3 = 1 / 0.00000000000000001;
	// fl3 = 14545456456465645464556456656554676565775755676757567.205445646545443254645456565456455476545867554577;

	// if (isnan(fl3))
	// 	std::cout << "is NAN !!!!! " << fl3 << std::endl;
	// else
	// 	std::cout << "is NUMBER !!!!! " << fl3 << std::endl;

	// int ret = fpclassify(fl3);

	// if (ret == FP_INFINITE)
	// 	std::cout << "Positive or negative infinity (overflow)" << fl3 << std::endl;
	// else if (ret == FP_NAN)
	// 	std::cout << "Not-A-Number" << fl3 << std::endl;
	// else if (ret == FP_ZERO)
	// 	std::cout << "Value of zero" << fl3 << std::endl;
	// else if (ret == FP_SUBNORMAL)
	// 	std::cout << "Sub-normal value (underflow)" << fl3 << std::endl;
	// else if (ret == FP_NORMAL)
	// 	std::cout << "Normal" << fl3 << std::endl;

	// std::cout.precision(5000);
	// std::cout << "float: " << fl << " + " << fl2 << " = " << fl3 << std::endl;

	// Factory factory = Factory();
	// IOperand const *one = factory.createOperand(eOperandType::Double, "50");
	// IOperand const *two = factory.createOperand(eOperandType::Double, "100");

	// std::vector<IOperand const *> v;

	// // void * p = &Factory::createOperand(eOperandType type, std::string const & value);
	// // (void)p;

	// v.push_back(one);
	// v.push_back(two);


	// std::vector<int*> *myVector = new std::vector<int*>;
	// int* p = new int;
	// myVector->push_back(p); 
	// delete  myVector;
	// delete p;


	return (0);
}
