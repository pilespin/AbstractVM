/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createOperand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:02:58 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/15 16:11:29 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class createOperand {

public:
	createOperand();
	~createOperand();
	createOperand(createOperand const &src);
	createOperand &operator=(createOperand const &rhs);

	int			getValue() const;
	void		empty();

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, createOperand &c);
