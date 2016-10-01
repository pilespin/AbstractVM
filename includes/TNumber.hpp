/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TNumber.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:18:12 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/01 22:16:16 by pilespin         ###   ########.fr       */
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

	

	class Infinite : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Infinite");
		}
	};

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

	class ValueOfZero : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Value of zero");
		}
	};

	class BadType : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("BadType");
		}
	};

	class NotANumber : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Not-A-Number");
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
		throw WTF();

	int ret = std::fpclassify(res);

	if (ret == FP_INFINITE)
		throw Infinite();
	else if (ret == FP_NAN)
		throw NotANumber();
	else if (ret == FP_ZERO)
		throw ValueOfZero();
	else if (ret == FP_SUBNORMAL)
		throw Underflow();

	if ((res) > this->getMaxValueOfPrecision(precision))
		throw Overflow();
	else if ((res) < this->getMinValueOfPrecision(precision))
		throw Underflow();

	if (precision == eOperandType::Int8)
		return (new NumberType<int8_t>(res));
	else if (precision == eOperandType::Int16)
		return (new NumberType<int16_t>(res));
	else if (precision == eOperandType::Int32)
		return (new NumberType<int32_t>(res));
	else if (precision == eOperandType::Float)
		return (new NumberType<float>(res));
	else if (precision == eOperandType::Double)
		return (new NumberType<double>(res));
	else
		throw WTF();
}

template <class T>
IOperand const *NumberType<T>::operator+( IOperand const & rhs ) const {

	double 	right 			= std::stof(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "+"));

}

template <class T>
IOperand const *NumberType<T>::operator-( IOperand const & rhs ) const {

	double 	right 			= std::stof(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "-"));

}

template <class T>
IOperand const *NumberType<T>::operator*( IOperand const & rhs ) const {

	double 	right 			= std::stof(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "*"));

}

template <class T>
IOperand const *NumberType<T>::operator/( IOperand const & rhs ) const {

	double 	right 			= std::stof(rhs.toString());
	double 	left 			= this->getValue();
	eOperandType precision 	= this->getMinimumPrecision(rhs);

	return (this->calc(left, right, precision, "/"));

}

template <class T>
IOperand const *NumberType<T>::operator%( IOperand const & rhs ) const {

	double 	right 			= std::stof(rhs.toString());
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
