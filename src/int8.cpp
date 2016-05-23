/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:39 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/23 20:59:03 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int8.hpp"

int8::int8() {

}

int8::int8(char val) {
	this->val = val;
}

int8::~int8() {

}

char	int8::getvalue() const 			{	return (this->val);			}
// void	int8::setvalue(char str) const 	{	return (this->val = str);	}

IOperand const *int8::operator+( IOperand const & rhs ) const {

	(void)rhs;
	return (new int8(this->getvalue() +((int8 &) rhs).getvalue()));
	// return (new int8(this->getvalue()));
}


// int8	int8::operator-(int8 const &rhs) const{
// 	return int8(this->val - rhs.getvalue());
// }

// int8	int8::operator*(int8 const &rhs) const{
// 	return int8(this->val * rhs.getvalue());
// }

// int8	int8::operator/(int8 const &rhs) const{
// 	return int8(this->val / rhs.getvalue());
// }

// int8	int8::operator%(int8 const &rhs) const{
// 	return int8(this->val % rhs.getvalue());
// }

std::string const  & int8::toString(void) const {

	std::string *str = new std::string("HI THIS IS BRAIN");
	std::string &strref = *str;
	return (strref);	
}

std::ostream &operator<<(std::ostream &o, int8 &c) {
	(void)c;
	// o << "value: " << (int)c.getvalue();
	o << "value: " << c.toString();
	// o << "value: ";
	return (o);
}
