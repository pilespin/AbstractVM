/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:01:27 by pilespin          #+#    #+#             */
/*   Updated: 2016/06/24 18:37:39 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int8.hpp"

int8::int8() 						{	this->_val = 0;	}

int8::int8(int val) 				{	this->_val = val;	}

int8::~int8()						{}

int8::int8(int8 const &src)	{	*this = src;	}

int8	&int8::operator=(int8 const &rhs) {

	(void)rhs;
	if (this != &rhs)
	{
		this->_val = rhs._val;
	}
	return (*this);
	// return (new &int8(5));
}

int8 &int8::operator+( int8 const & rhs ) {
// int8 const *int8::operator+(int8 const &rhs) const {

	(void)rhs;
	this->_val += rhs.getValue();
	// return (new int8(this->getValue() + ((int8 &)rhs).getValue()));
	// return (this);
	// int8 tmp;
	// tmp = new int8(5)
	//return (new int8(5));
	return (*this);

	// return (new int8(this->getValue()));
}

std::ostream &operator<<(std::ostream &o, int8 &c) {
	(void)c;
	o << "int8: " << c.getValue() << " ";
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
