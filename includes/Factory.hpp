/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:44:48 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/30 18:27:58 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"

class Factory {

public:
	Factory();
	~Factory();
	Factory(Factory const &src);
	// Factory &operator=(Factory const &rhs);

	IOperand const *createOperand( eOperandType type, std::string const & value ) const;

	void		empty();

	class ValueTooHigh : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Bad value is too high");
		}
	};

	class ValueTooLow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Bad value is too Low");
		}
	};

	// class BadOperand : public std::exception {
	// public:
	// 	virtual const char *what() const throw() {
	// 		return ("Bad Operande");
	// 	}
	// };

private:
	// std::vector<IOperand const *> v;
	// typedef	IOperand const * (Factory::*fct)( std::string const & ) const;
	std::vector<IOperand const * (Factory::*)( std::string const & ) const> fct_create;
	// std::vector<fct> fct_create;
	
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};

std::ostream &operator<<(std::ostream &o, Factory &c);
