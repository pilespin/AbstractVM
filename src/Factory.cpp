/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:44:48 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/28 20:09:25 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "IOperand.hpp"
#include "TNumber.hpp"
// #include "int8.hpp"

Factory::Factory() 						{}

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
	// o << "Factory: " << c.getValue() << " ";
	o << "Factory: " << "I'm a Factory";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
// int		Factory::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

IOperand const *Factory::createOperand( eOperandType type, std::string const & value ) const {
	(void)value;
	(void)type;

	if (type == eOperandType::Int8)
		return (this->createInt8(value));
	else if (type == eOperandType::Int16)
		return (this->createInt16(value));
	else if (type == eOperandType::Int32)
		return (this->createInt32(value));
	else if (type == eOperandType::Float)
		return (this->createFloat(value));
	else if (type == eOperandType::Double)
		return (this->createDouble(value));
	else
		throw BadOperand();
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

	float tmp_float_max = FLT_MAX;
	float tmp_float_min = FLT_MIN;

	std::cout << "valuetest: " << val << std::endl;
	std::cout << "value max: " << tmp_float_max << std::endl;
	std::cout << "value min: " << tmp_float_min << std::endl;


	if (val > tmp_float_max)
		throw ValueTooHigh();
	else if (val < tmp_float_min)
		throw ValueTooLow();

	return (new NumberType<float>(static_cast<float>(val)));
}

IOperand const *Factory::createDouble( std::string const & value ) const {

	double val = std::atof(value.c_str());

	std::cout << "valutest: " << val << std::endl;

	if (val > DBL_MAX)
		throw ValueTooHigh();
	else if (val < DBL_MIN)
		throw ValueTooLow();

	return (new NumberType<double>(static_cast<double>(val)));
}

void	Factory::empty() {

}
