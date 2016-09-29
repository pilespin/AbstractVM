/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TNumber.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:18:12 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/29 16:41:25 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <project.hpp>
#include "IOperand.hpp"

template <class T>
class NumberType : public IOperand {

public:
	NumberType();
	NumberType(T val);
	~NumberType();

	T 					getValue() const;
	double				getMaxValueOfPrecision( int precision ) const;
	double				getMinValueOfPrecision( int precision ) const;
	int					getMinimumPrecision( IOperand const &value ) const;

	int 				getPrecision() const;
	eOperandType 		getType( void ) const;
	IOperand const 		*operator+( IOperand const & rhs ) const;
	std::string const 	&toString( void ) const;

	class Overflow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Overflow");
		}
	};

	class Underflow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Underflow");
		}
	};

	class BadType : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("BadType");
		}
	};

	class WTF : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("W.T.F !!!");
		}
	};

// std::ostream &operator<<(std::ostream &o, IOperand const *c);

private:
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
NumberType<T>::NumberType(T val) 	{	this->_val = val;	}  

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

	if (!id.compare("a"))
		return (eOperandType::Int8);
	else if (!id.compare("s"))
		return (eOperandType::Int16);
	else if (!id.compare("i"))
		return (eOperandType::Int32);
	else if (!id.compare("f"))
		return (eOperandType::Float);
	else if (!id.compare("d"))
		return (eOperandType::Double);
	else
		throw WTF();
}

template <class T>
std::string const & NumberType<T>::toString( void ) const {

	std::string const *str = new std::string(std::to_string(this->getValue()));
	std::string const &ref = *str;

	return(ref);
}

template <class T>
IOperand const *NumberType<T>::operator+( IOperand const & rhs ) const {
	(void)rhs;


	std::string::size_type sz;

	long double right 	= std::stof(rhs.toString(), &sz);
	long double 	left 	= this->getValue();
	int	precision 	= this->getMinimumPrecision(rhs);

	if ((left + right) > this->getMaxValueOfPrecision(precision))
		throw Overflow();
	else if ((left + right) < this->getMinValueOfPrecision(precision))
		throw Underflow();

	if (precision == PRECISION_INT8)
		return (new NumberType<int8_t>(left + right));
	else if (precision == PRECISION_INT16)
		return (new NumberType<int16_t>(left + right));
	else if (precision == PRECISION_INT32)
		return (new NumberType<int32_t>(left + right));
	else if (precision == PRECISION_FLT)
		return (new NumberType<float>(left + right));
	else if (precision == PRECISION_DBL)
		return (new NumberType<double>(left + right));
	else
		throw WTF();

}

template <class T>
int NumberType<T>::getMinimumPrecision( IOperand const &value) const {

	int left 	= this->getPrecision();
	int right 	= value.getPrecision();

	if (left > right)
		return (left);
	else
		return (right);
}

template <class T>
double NumberType<T>::getMaxValueOfPrecision( int precision) const {

	if (precision == PRECISION_INT8)
		return (INT8_MAX);
	else if (precision == PRECISION_INT16)
		return (INT16_MAX);
	else if (precision == PRECISION_INT32)
		return (INT32_MAX);
	else if (precision == PRECISION_FLT)
		return (FLT_MAX);
	else if (precision == PRECISION_DBL)
		return (DBL_MAX);
	else
		throw BadType();
}

template <class T>
double NumberType<T>::getMinValueOfPrecision( int precision) const {

	if (precision == PRECISION_INT8)
		return (INT8_MIN);
	else if (precision == PRECISION_INT16)
		return (INT16_MIN);
	else if (precision == PRECISION_INT32)
		return (INT32_MIN);
	else if (precision == PRECISION_FLT)
		return (-FLT_MAX);
	else if (precision == PRECISION_DBL)
		return (-DBL_MAX);
	else
		throw BadType();
}
