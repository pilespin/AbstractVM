/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TNumber.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:18:12 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/07 19:52:18 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <project.hpp>
#include "Exception.hpp"
#include "IOperand.hpp"

template <class T>
class NumberType : public IOperand, public Exception {

public:
	NumberType();
	NumberType(T val);
	~NumberType();

	T 					getValue() const;
	double				getMaxValueOfPrecision( int precision ) const;
	double				getMinValueOfPrecision( int precision ) const;
	eOperandType		getMinimumPrecision( IOperand const &value ) const;

	int 				getPrecision() const;
	eOperandType 		getType( void ) const;
	IOperand const 		*operator+( IOperand const & rhs ) const;
	IOperand const 		*operator-( IOperand const & rhs ) const;
	IOperand const 		*operator*( IOperand const & rhs ) const;
	IOperand const 		*operator/( IOperand const & rhs ) const;
	IOperand const 		*operator%( IOperand const & rhs ) const;
	IOperand const 		*calc(double left, double right, eOperandType precision, std::string operation) const;
	std::string const 	&toString( void ) const;

// std::ostream &operator<<(std::ostream &o, IOperand const *c);

private:
	std::map< std::string, eOperandType > 	strToIoperand;
	T _val;

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// std::ostream &operator<<(std::ostream &o, IOperand const *c);

// template <class T>
// std::ostream &operator<<(std::ostream &o, IOperand const *c) {
// 	(void)c;

// 	// o << "int8: " << reinterpret_cast<int8 const *>(c)->getValue() << " ";
// 	o << "int8: " << c->toString() << " lolol";
// 	return (o);
// }

///////////////////////////////////////////////////////////////////////////////
template <class T>
T NumberType<T>::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

template <class T>
NumberType<T>::NumberType() 		{}  

template <class T>
NumberType<T>::NumberType(T val) {

	this->_val = val;

}  

template <class T>
NumberType<T>::~NumberType() 		{}

///////////////////////////////////////////////////////////////////////////////

template <class T>
int  NumberType<T>::getPrecision( void ) const {

	eOperandType io = this->getType();
	return(static_cast<int>(io));
}

template <class T>
eOperandType  NumberType<T>::getType( void ) const {

	T value = this->getValue();
	std::string id = typeid(value).name();

	std::map< std::string, eOperandType > 	strToIoperand;

	strToIoperand["a"] = eOperandType::Int8;
	strToIoperand["s"] = eOperandType::Int16;
	strToIoperand["i"] = eOperandType::Int32;
	strToIoperand["f"] = eOperandType::Float;
	strToIoperand["d"] = eOperandType::Double;

	return (strToIoperand[id]);
	
}

template <class T>
std::string const & NumberType<T>::toString( void ) const {

	std::string const *str = new std::string(std::to_string(this->getValue()));
	std::string const &ref = *str;

	return(ref);
}

template <class T>
IOperand const *NumberType<T>::calc(double left, double right, eOperandType precision, std::string operation) const {

	long double res = 0;

	if (!operation.compare("+"))
		res = left + right;
	else if (!operation.compare("-"))
		res = left - right;
	else if (!operation.compare("*"))
		res = left * right;
	else if (!operation.compare("/"))
		res = left / right;
	else if (!operation.compare("%"))
		res = fmod(left, right);
	else
		throw Error("WTF");

	int ret = std::fpclassify(res);

	if (ret == FP_INFINITE)
		throw Error("Infinite value");
	else if (ret == FP_NAN)
		throw Error("Not a number");
	// else if (ret == FP_ZERO)
	// 	throw ValueOfZero();
	else if (ret == FP_SUBNORMAL)
		throw Error("Underflow");

	if ((res) > this->getMaxValueOfPrecision(precision))
		throw Error("Overflow");
	else if ((res) < this->getMinValueOfPrecision(precision))
		throw Error("Underflow");

	return (new NumberType<T>(res));

}

template <class T>
IOperand const *NumberType<T>::operator+( IOperand const & rhs ) const {

	double 	right 			= std::stod(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "+"));

}

template <class T>
IOperand const *NumberType<T>::operator-( IOperand const & rhs ) const {

	double 	right 			= std::stod(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "-"));

}

template <class T>
IOperand const *NumberType<T>::operator*( IOperand const & rhs ) const {

	double 	right 			= std::stod(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "*"));

}

template <class T>
IOperand const *NumberType<T>::operator/( IOperand const & rhs ) const {

	double 	right 			= std::stod(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "/"));

}

template <class T>
IOperand const *NumberType<T>::operator%( IOperand const & rhs ) const {

	double 	right 			= std::stod(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "%"));

}

template <class T>
eOperandType NumberType<T>::getMinimumPrecision( IOperand const &value) const {

	int left 	= this->getPrecision();
	int right 	= value.getPrecision();

	if (left > right)
		return (static_cast<eOperandType>(left));
	else
		return (static_cast<eOperandType>(right));
}

template <class T>
double NumberType<T>::getMaxValueOfPrecision( int precision) const {

	double valMax[] = {INT8_MAX, INT16_MAX, INT32_MAX, FLT_MAX, DBL_MAX};

	return (valMax[precision]);
}

template <class T>
double NumberType<T>::getMinValueOfPrecision( int precision) const {

	double valMin[] = {INT8_MIN, INT16_MIN, INT32_MIN, -FLT_MAX, -DBL_MAX};
	
	return (valMin[precision]);
}
