/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:24:46 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/07 21:12:11 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.hpp"

Stack::Stack() {	

	this->_val = 0;
	this->goodExit = FALSE;	
}

Stack::~Stack()					{}

Stack::Stack(Stack const &src)	{	*this = src;	}

Stack	&Stack::operator=(Stack const &rhs) {

	if (this != &rhs)
	{
		this->_val 		= rhs._val;
		this->goodExit 	= rhs.goodExit;
		this->list 		= rhs.list;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Stack &c) {
	o << "Stack: " << c.getValue() << " ";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
int					Stack::getValue() 	const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

void				Stack::checkExit() 	const	{

	if (!this->goodExit)
		throw Error("This program was not terminated correctly, You need to use the \"exit\" command for exit properly, use this command is ABSOLUTELY NEEDED if you don't want to see this ERROR!");	

}

IOperand const *	Stack::getAndPopOnStack() {

	if (this->list.empty())
		throw Error("Empty Stack");
	IOperand const *one = this->list.front();
	this->list.pop_front();
	return (one);

}

void	Stack::operateCore(eOperatorType op) {

	IOperand const *left = this->getAndPopOnStack();
	IOperand const *right = this->getAndPopOnStack();
	IOperand const *res;

	if (op == eOperatorType::Add)
		res = *left + *right;
	else if (op == eOperatorType::Sub)
		res = *left - *right;
	else if (op == eOperatorType::Mul)
		res = *left * *right;
	else if (op == eOperatorType::Div)
		res = *left / *right;
	else if (op == eOperatorType::Mod)
		res = *left % *right;
	else
		throw Error("WTF2");

	this->list.push_front(res);

}

void	Stack::push(IOperand const *value) {

	this->list.push_front(value);

}

void	Stack::pop() {

	if (this->list.empty())
		throw Error("Empty Stack");
	this->list.pop_front();

}

void	Stack::dump() {

	if (this->list.empty())
		std::cout << "Empty stack" << std::endl;
	else
	{
		for (auto it = this->list.begin(); it != this->list.end(); ++it)
			std::cout << (*it)->toString() << std::endl;
	}
}

void	Stack::assert(std::string value) {

	if (this->list.empty())
		throw Error("Assertion error");

	auto 	it 			= this->list.begin();
	double 	left 		= std::stod((*it)->toString());
	double 	right 		= std::stod(value);

	if (left != right)
		throw Error("Assertion error");

}

void	Stack::operate(eOperatorType op) {

	if (this->list.size() >= 2)
		this->operateCore(op);
	else
		throw Error("Need a least two value in stack");

}

void	Stack::print() {

	IOperand const *one = this->getAndPopOnStack();

	if (one->getType() == eOperandType::Int8)
	{
		char val = std::stoi(one->toString());
		std::cout << val << std::endl;
	}
	else
		throw Error("Assertion error");
}

void	Stack::exit() {
	this->goodExit = TRUE;
}
