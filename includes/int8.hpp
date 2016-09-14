/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:01:27 by pilespin          #+#    #+#             */
/*   Updated: 2016/06/25 21:12:09 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"

class int8 : public IOperand{

public:
	int8();
	~int8();
	int8(int8_t val);
	int8(int8 const &src);
	// int8	*operator=(int8 const *rhs);
	IOperand const * operator+( IOperand const & rhs ) const;
	std::string const & toString( void ) const;

	int			getValue() const;
	void		empty();
	// std::string	toString() const;

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

private:
	int8_t _val;
	int8_t _type;
	int8_t _precision;
};

std::ostream &operator<<(std::ostream &o, IOperand const *c);
