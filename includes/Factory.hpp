/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:44:48 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/07 20:58:04 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Exception.hpp"
#include "IOperand.hpp"

class Factory : public Exception{

public:
	Factory();
	~Factory();
	Factory(Factory const &src);
	Factory &operator=(Factory const &rhs);

	IOperand const *createOperand( eOperandType type, std::string const & value ) const;

	void		empty();

private:
	// typedef	IOperand const * (Factory::*fct)( std::string const & ) const;
	// std::vector<fct> fct_create;
	std::vector<IOperand const * (Factory::*)( std::string const & ) const> fct_create;
	
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};

std::ostream &operator<<(std::ostream &o, Factory &c);
