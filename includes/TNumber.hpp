
#pragma once

#include <project.hpp>
#include "IOperand.hpp"

template <class T>
class NumberType : public IOperand {

public:
    NumberType();
    NumberType(T val);
    ~NumberType();

    T getValue() const;

	IOperand const * operator+( IOperand const & rhs ) const;
	std::string const & toString( void ) const;

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

    // T create (T const& val);
private:
	T _val;

};

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
NumberType<T>::NumberType() {

}  

template <class T>
NumberType<T>::NumberType(T val) {
		this->_val = val;
}  

template <class T>
NumberType<T>::~NumberType(void) {

}

// template <class T>
// T NumberType<T>::create (T const& val) 
// {
// 	return (val); 
// }

template <class T>
std::string const & NumberType<T>::toString( void ) const {

	std::string const *str = new std::string(std::to_string(this->getValue()));
	std::string const &ref = *str;

	return(ref);
}

template <class T>
IOperand const *NumberType<T>::operator+( IOperand const & rhs ) const {
	(void)rhs;

	int8_t right = std::atoi(rhs.toString().c_str());
	int8_t left = this->getValue();

	if (left + right > INT8_MAX)
		throw Overflow();
	else if ((left + right) < INT8_MIN)
		throw Underflow();

	return (new NumberType<T>(left + right));
}
