/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:32 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/20 20:58:38 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

#include "IOperand.hpp"
#include <iostream>

class int8 : public IOperand {

public:
	int8();
	~int8();

	int8(char val);

	IOperand const *operator+( IOperand const & rhs ) const;
	// int8 	operator-(int8 const &rhs) const;
	// int8 	operator*(int8 const &rhs) const;
	// int8 	operator/(int8 const &rhs) const;
	// int8 	operator%(int8 const &rhs) const;
	// std::string &toString( void ) const;
	char	getvalue() const ;

private:
	char val;
};

std::ostream &operator<<(std::ostream &o, IOperand &c);

#endif
