/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:01:27 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/14 15:54:50 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int8.hpp"

int8::int8() {	
	this->_val = 0;	
	this->_type = TYPE_INT8;
	this->_precision = TYPE_INT8;
}

int8::int8(int8_t val) 				{	this->_val = val;	}

int8::~int8()						{}

int8::int8(int8 const &src)	{	*this = src;	}

// int8	*int8::operator=(int8 const *rhs) {

// 	(void)rhs;
// 	if (this != rhs)
// 	{
// 		this->_val = rhs->_val;
// 	}
// 	return (this);
// }

std::string const & int8::toString( void ) const {

	std::string const *str = new std::string(std::to_string(this->getValue()));
	std::string const &ref = *str;

	return(ref);
}

IOperand const *int8::operator+( IOperand const & rhs ) const {
	(void)rhs;

	int8_t right = std::atoi(rhs.toString().c_str());
	int8_t left = this->getValue();

	if (left + right > INT8_MAX)
		throw Overflow();
	else if ((left + right) < INT8_MIN)
		throw Underflow();

	return (new int8(left + right));
}

std::ostream &operator<<(std::ostream &o, IOperand const *c) {
	(void)c;

	// o << "int8: " << reinterpret_cast<int8 const *>(c)->getValue() << " ";
	o << "int8: " << c->toString() << " ";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
int		int8::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

// std::string const	& int8::toString(void) const {

// 	std::string *str = new std::string("HI THIS IS BRAIN");
// 	std::string &strref = *str;
// 	return (strref);	
// }

void	int8::empty() {

}
