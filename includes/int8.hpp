/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:32 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/19 19:14:57 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

#include <iostream>

class int8
{

public:
	int8();
	~int8();

	int8(char val);

	int8	operator+(int8 const &rhs) const;
	int8 	operator-(int8 const &rhs) const;
	int8 	operator*(int8 const &rhs) const;
	int8 	operator/(int8 const &rhs) const;
	int8 	operator%(int8 const &rhs) const;
	char	getvalue() const ;

private:
	char val;
};

std::ostream &operator<<(std::ostream &o, int8 &c);

#endif
