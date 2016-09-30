/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:44:48 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/30 18:28:00 by pilespin         ###   ########.fr       */
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

// Factory	&Factory::operator=(Factory const &rhs) {

// 	if (this != &rhs)
// 	{
// 		this->_val = rhs._val;
// 	}
// 	return (*this);
// }

std::ostream &operator<<(std::ostream &o, Factory &c) {
	(void)c;
	o << "Factory: " << "I'm a Factory";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
// int		Factory::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

IOperand const *Factory::createOperand( eOperandType type, std::string const & value ) const {
	(void)value;
	(void)type;

	int precision = static_cast<int>(type);

	return( (this->*(fct_create[precision]))(value) );
}

IOperand const *Factory::createInt8( std::string const & value ) const {

	double val = std::atof(value.c_str());

	if (val > INT8_MAX)
		throw ValueTooHigh();
	else if (val < INT8_MIN)
		throw ValueTooLow();

	return (new NumberType<int8_t>(static_cast<int8_t>(val)));
}

IOperand const *Factory::createInt16( std::string const & value ) const {

	double val = std::atof(value.c_str());

	if (val > INT16_MAX)
		throw ValueTooHigh();
	else if (val < INT16_MIN)
		throw ValueTooLow();

	return (new NumberType<int16_t>(static_cast<int16_t>(val)));
}

IOperand const *Factory::createInt32( std::string const & value ) const {

	double val = std::atof(value.c_str());

	if (val > INT32_MAX)
		throw ValueTooHigh();
	else if (val < INT32_MIN)
		throw ValueTooLow();

	return (new NumberType<int32_t>(static_cast<int32_t>(val)));
}

IOperand const *Factory::createFloat( std::string const & value ) const {

	double val = std::atof(value.c_str());

	if (val > std::numeric_limits<float>::max())
		throw ValueTooHigh();
	else if (val < std::numeric_limits<float>::lowest())
		throw ValueTooLow();

	return (new NumberType<float>(static_cast<float>(val)));
}

IOperand const *Factory::createDouble( std::string const & value ) const {

	double val = std::atof(value.c_str());

	if (val > std::numeric_limits<double>::max())
		throw ValueTooHigh();
	else if (val < std::numeric_limits<double>::lowest())
		throw ValueTooLow();

	return (new NumberType<double>(static_cast<double>(val)));
}

void	Factory::empty() {

}
