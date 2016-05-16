/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:30:32 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/16 17:06:29 by pilespin         ###   ########.fr       */
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
	
private:
	char val;
};

#endif
