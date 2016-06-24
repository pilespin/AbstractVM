/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:01:27 by pilespin          #+#    #+#             */
/*   Updated: 2016/06/24 18:36:31 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"
#include <iostream>

class int8 {

public:
	int8();
	~int8();
	int8(int val);
	int8(int8 const &src);
	int8  &operator=(int8 const &rhs);
	int8 &operator+(int8 const &rhs);
	// int8 const *operator+(int8 const &rhs) const;

	int			getValue() const;
	void		empty();
	// std::string	toString() const;

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, int8 &c);
