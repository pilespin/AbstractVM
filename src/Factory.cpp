/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:44:48 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/07 20:59:04 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "IOperand.hpp"
#include "TNumber.hpp"

Factory::Factory() {
	this->fct_create.push_back(&Factory::createInt8);
	this->fct_create.push_back(&Factory::createInt16);
	this->fct_create.push_back(&Factory::createInt32);
	this->fct_create.push_back(&Factory::createFloat);
	this->fct_create.push_back(&Factory::createDouble);
}

Factory::~Factory()						{}

Factory::Factory(Factory const &src)	{	*this = src;	}

Factory	&Factory::operator=(Factory const &rhs) {

	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Factory &c) {
	(void)c;
	o << "Factory: " << "I'm a Factory";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
// int		Factory::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

IOperand const *Factory::createOperand( eOperandType type, std::string const & value ) const {

	return( (this->*(fct_create[type]))(value) );
}

IOperand const *Factory::createInt8( std::string const & value ) const {

	long double val = std::strtold(value.c_str(), NULL);

	if (val > INT8_MAX)
		throw Error("Overflow");
	else if (val < INT8_MIN)
		throw Error("Underflow");

	return (new NumberType<int8_t>(val));
}

IOperand const *Factory::createInt16( std::string const & value ) const {

	long double val = std::strtold(value.c_str(), NULL);

	if (val > INT16_MAX)
		throw Error("Overflow");
	else if (val < INT16_MIN)
		throw Error("Underflow");

	return (new NumberType<int16_t>(val));
}

IOperand const *Factory::createInt32( std::string const & value ) const {

	long double val = std::strtold(value.c_str(), NULL);

	if (val > INT32_MAX)
		throw Error("Overflow");
	else if (val < INT32_MIN)
		throw Error("Underflow");

	return (new NumberType<int32_t>(val));
}

IOperand const *Factory::createFloat( std::string const & value ) const {

	long double val = std::strtold(value.c_str(), NULL);

	if (val > std::numeric_limits<float>::max())
		throw Error("Overflow");
	else if (val < std::numeric_limits<float>::lowest())
		throw Error("Underflow");

	return (new NumberType<float>(val));
}

IOperand const *Factory::createDouble( std::string const & value ) const {

	long double val = std::strtold(value.c_str(), NULL);

	if (val > std::numeric_limits<double>::max())
		throw Error("Overflow");
	else if (val < std::numeric_limits<double>::lowest())
		throw Error("Underflow");

	return (new NumberType<double>(val));
}

void	Factory::empty() {

}
