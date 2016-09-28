/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TNumber.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:18:12 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/28 13:20:55 by pilespin         ###   ########.fr       */
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
	T 					getMaxValueOfType(T value);

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

    // T create (T const& val);
private:
	T 				_val;
	// eOperandType	io;

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// std::ostream &operator<<(std::ostream &o, IOperand const *c);

template <class T>
std::ostream &operator<<(std::ostream &o, IOperand const *c) {
	(void)c;

	// o << "int8: " << reinterpret_cast<int8 const *>(c)->getValue() << " ";
	o << "int8: " << c->toString() << " ";
	return (o);
}

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

	T right = std::atof(rhs.toString().c_str());
	T left = this->getValue();

	// T test = this->getMaxValueOfType(left);
	// (void)test;
	// std::cout << "Max value: " << this->getMaxValueOfType(left) << std::endl;

	// T lol = this->getMaxValueOfType(left);
	// if (left + right > INT8_MAX)
	// 	throw Overflow();
	// else if ((left + right) < INT8_MIN)
	// 	throw Underflow();

	return (new NumberType<T>(left + right));
}

// uint8_t 	== "h";
// uint16_t 	== "t";
// uint32_t 	== "j";
// float 		== "f";
// double 		== "d";

// template <class T>
// T NumberType<T>::getMaxValueOfType(T value) {

// 	std::string id = typeid(value).name();

// 	return(42);
// 	// if (id.compare("h"))
// 	// 	return (INT8_MAX);
// 	// else if (id.compare("t"))
// 	// 	return (INT16_MAX);
// 	// else if (id.compare("j"))
// 	// 	return (INT32_MAX);
// 	// // else if (id.compare("f"))
// 	// // 	return (FLOAT_MAX);
// 	// // else if (id.compare("d"))
// 	// // 	return (DOUBLE_MAX);
// 	// else
// 	// 	throw BadType();
// 	// return (0);
// }