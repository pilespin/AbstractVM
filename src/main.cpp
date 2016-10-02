/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/02 17:09:48 by pilespin         ###   ########.fr       */
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
		ft_test_add();

		Stack s = Stack();
		Parse p = Parse();
		(void)s;

		Factory factory = Factory();
		IOperand const *one = factory.createOperand(eOperandType::Double, "50");
		IOperand const *two = factory.createOperand(eOperandType::Int8, "90");

		(void)one;
		(void)two;
		s.push(one);
		s.push(two);

		s.dump();
		s.assert("+90.0000");

		// s.pop();
		// s.pop();
		s.dump();
		s.operate(eOperatorType::Mul);
		s.push(two);
		s.push(two);
		s.push(two);
		s.push(two);
		s.dump();
		s.print();
		s.print();
		s.print();
		s.print();

		p.readFile("sample");


	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}

	// std::string s ("this subject has a submarine as a subsequence");
	// std::smatch m;
 //  	std::regex e ("sub");   // matches words beginning by "sub"

 //  	std::cout << "Target sequence: " << s << std::endl;
 //  	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
 //  	std::cout << "The following matches and submatches were found:" << std::endl;

 //  	while (std::regex_search (s,m,e))
 //  	{
 //  		for (auto x:m) std::cout << x << " ";
 //  			std::cout << std::endl;
 //  		s = m.suffix().str();
 //  	}


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
