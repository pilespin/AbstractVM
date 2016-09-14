/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:34:00 by pilespin          #+#    #+#             */
/*   Updated: 2016/06/25 20:42:19 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>

class IOperand {
public:
	// virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
	// virtual eOperandType getType( void ) const = 0; // Type of the instance
	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
	// virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
	// virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
	// virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
	// virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
	virtual std::string const & toString( void ) const = 0; // String representation of the instance
	// virtual ~IOperand( void ) {}

	// int8	*operator+(int8 const &rhs) const;
};
