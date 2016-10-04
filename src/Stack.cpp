/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:24:46 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/04 18:00:23 by pilespin         ###   ########.fr       */
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

	this->list.push_front(value);

}

void	Stack::pop() {

	if (this->list.empty())
		throw EmptyStack();
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

	auto 	it 			= this->list.begin();
	double 	left 		= std::stof((*it)->toString());
	double 	right 		= std::stof(value);

	if (left != right)
		throw AssertError();

}

void	Stack::operate(eOperatorType op) {

	if (this->list.size() >= 2)
		this->operateCore(op);
	else
		throw AddError();

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
