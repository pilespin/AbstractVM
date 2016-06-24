/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:01:27 by pilespin          #+#    #+#             */
/*   Updated: 2016/06/24 21:27:23 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"
#include <iostream>

class int8 : public IOperand{

public:
	int8();
	~int8();
	int8(int val);
	int8(int8 const &src);
	// int8	*operator=(int8 const *rhs);
	// int8	*operator+(IOperand const &rhs);
	IOperand const * operator+( IOperand const & rhs ) const;
	// int8 const *operator+(int8 const &rhs) const;

	int			getValue() const;
	void		empty();
	// std::string	toString() const;

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, IOperand const *c);
