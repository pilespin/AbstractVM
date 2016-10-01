/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:24:46 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/01 21:58:07 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.hpp"

Stack::Stack() 						{	this->_val = 0;	}

Stack::~Stack()						{}

Stack::Stack(Stack const &src)	{	*this = src;	}

// Stack	&Stack::operator=(Stack const &rhs) {

// 	if (this != &rhs)
// 	{
// 		this->_val = rhs._val;
// 	}
// 	return (*this);
// }

std::ostream &operator<<(std::ostream &o, Stack &c) {
	o << "Stack: " << c.getValue() << " ";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
int							Stack::getValue() 	const	{	return (this->_val);	}
std::list<IOperand const *>	Stack::getList() 	const	{	return (this->list);	}
///////////////////////////////////////////////////////////////////////////////

IOperand const *	Stack::getAndPopOnStack() {

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
		throw WTF();

	this->list.push_front(res);

}

void	Stack::push(IOperand const *value) {

	std::cout << "Push: ";
	
	this->list.push_front(value);

	std::cout << "OK" << std::endl;

}

void	Stack::pop() {

	std::cout << "Pop: ";

	if (this->list.empty())
		throw EmptyStack();
	this->list.pop_front();

	std::cout << "OK" << std::endl;

}

void	Stack::dump() {

	std::cout << "Dump: ";

	if (this->list.empty())
		std::cout << "empty stack" << std::endl;
	else
	{
		std::cout << std::endl;
		for (auto it = this->list.begin(); it != this->list.end(); ++it)
			std::cout << (*it)->toString() << std::endl;
	}
}

void	Stack::assert(std::string value) {

	(void)value;

	auto 	it 			= this->list.begin();
	double 	left 		= std::stof((*it)->toString());
	double 	right 		= std::stof(value);

	std::cout << "Assert: ";

	if (left == right)
		std::cout << "OK";
	else
	{
		std::cout << "KO" << std::endl;
		throw AssertError();
	}
	std::cout << std::endl;

}

void	Stack::operate(eOperatorType op) {

	std::cout << "Add: ";

	if (this->list.size() >= 2)
	{
		this->operateCore(op);
		std::cout << "OK";
	}
	else
	{
		std::cout << "KO" << std::endl;
		throw AddError();
	}
	std::cout << std::endl;

}

void	Stack::print() {

	IOperand const *one = this->getAndPopOnStack();

	if (one->getType() == eOperandType::Int8)
	{
		char val = std::stoi(one->toString());
		std::cout << val << std::endl;
	}
	else
		throw AssertError();
}

void	Stack::exit() {

}
