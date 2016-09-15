/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createOperand.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:07:45 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/15 16:11:18 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "createOperand.hpp"

createOperand::createOperand() 						{	this->_val = 0;	}

createOperand::~createOperand()						{}

createOperand::createOperand(createOperand const &src)	{	*this = src;	}

createOperand	&createOperand::operator=(createOperand const &rhs) {

	if (this != &rhs)
	{
		this->_val = rhs._val;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, createOperand &c) {
	o << "createOperand: " << c.getValue() << " ";
	return (o);
}
///////////////////////////////////////////////////////////////////////////////
int		createOperand::getValue() const	{	return (this->_val);	}
