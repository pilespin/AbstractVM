/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/07 17:31:59 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Exception {

public:
	Exception();
	~Exception();
	Exception(Exception const &src);
	Exception &operator=(Exception const &rhs);

	class Error : public std::exception {
	public:
		Error(std::string str) { 
			this->line += str; 
		}
		virtual const char *what() const throw() {
			return (this->line.c_str());
		}
	private:
		std::string line;
	};

	int			getValue() const;
	void		empty();

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, Exception &c);
