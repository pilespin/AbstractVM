/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:39 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/20 20:58:44 by pilespin         ###   ########.fr       */
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

char	int8::getvalue() const {	return (this->val);	}

IOperand const *int8::operator+( IOperand const & rhs ) const {

	return (new int8(this->getvalue() +((int8 &) rhs).getvalue()));
}

// std::string  &int8::toString( void ) const {
// // 	std::string str = new std::string("Hello");
// 	std::string &str = new std::string("Hello");

// 	return (str);
// }

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

std::ostream &operator<<(std::ostream &o, IOperand &c) {
	(void)c;
	// o << "value: " << (int)c.getvalue() ;
	o << "value: ";
	return (o);
}
