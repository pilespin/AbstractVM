/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createOperand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:02:58 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/15 17:52:50 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"

class createOperand {

public:
	createOperand();
	~createOperand();
	createOperand(createOperand const &src);
	createOperand &operator=(createOperand const &rhs);

	IOperand const *createOperand( eOperandType type, std::string const & value ) const;
	IOperand const *createInt8( std::string const & value ) const;

	int			getValue() const;
	void		empty();

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, createOperand &c);
