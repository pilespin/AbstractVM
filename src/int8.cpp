/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:39 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/19 19:15:18 by pilespin         ###   ########.fr       */
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

int8	int8::operator+(int8 const &rhs) const{
	return int8(this->val + rhs.getvalue());
}

int8	int8::operator-(int8 const &rhs) const{
	return int8(this->val - rhs.getvalue());
}

int8	int8::operator*(int8 const &rhs) const{
	return int8(this->val * rhs.getvalue());
}

int8	int8::operator/(int8 const &rhs) const{
	return int8(this->val / rhs.getvalue());
}

int8	int8::operator%(int8 const &rhs) const{
	return int8(this->val % rhs.getvalue());
}

std::ostream &operator<<(std::ostream &o, int8 &c) {
	o << "value: " << (int)c.getvalue() ;
	return (o);
}
