/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:44:48 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/15 19:29:22 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "IOperand.hpp"
#include "int8.hpp"

Factory::Factory() 						{}

Factory::~Factory()						{}

Factory::Factory(Factory const &src)	{	*this = src;	}

Factory	&Factory::operator=(Factory const &rhs) {

	if (this != &rhs)
	{
		this->_val = rhs._val;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Factory &c) {
	o << "Factory: " << c.getValue() << " ";
	return (o);
}
///////////////////////////////////////////////////////////////////////////////
int		Factory::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

IOperand const *Factory::createOperand( eOperandType type, std::string const & value ) const {
	(void)value;
	(void)type;

	if (type == eOperandType::Int8)
		return (this->createInt8(value));
	else
		throw BadOperand();

}

IOperand const *Factory::createInt8( std::string const & value ) const {

	double val = std::atof(value.c_str());

	if (val > INT8_MAX)
		throw ValueTooHigh();
	else if (val < INT8_MIN)
		throw ValueTooLow();

	return (new int8(val));

}

void	Factory::empty() {

}
