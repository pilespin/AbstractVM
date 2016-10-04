/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/04 17:05:37 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

Exception::Exception() 						{	this->_val = 0;	}

Exception::~Exception()						{}

Exception::Exception(Exception const &src)	{	*this = src;	}

Exception	&Exception::operator=(Exception const &rhs) {

	if (this != &rhs)
	{
		this->_val = rhs._val;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Exception &c) {
	o << "Exception: " << c.getValue() << " ";
	return (o);
}
///////////////////////////////////////////////////////////////////////////////
int		Exception::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////
void	Exception::empty() {

}
