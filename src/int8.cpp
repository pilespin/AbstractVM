/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:39 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/16 18:11:01 by pilespin         ###   ########.fr       */
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

int8 &int8::operator=(int8 const &rhs) {

	(void)rhs;
	return (this->val);
}

int8 &int8::operator+(int8 const &rhs) {

	if (this != &rhs)
	{
		this->val += rhs.val;
	}
	return (*this);
}
