/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/04 19:55:15 by pilespin         ###   ########.fr       */
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

	class BadExit : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Bad Exit");
		}
	};

	class EmptyStack : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Empty Stack");
		}
	};

	class SyntaxError : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Syntax error");
		}
	};

	class BadCommand : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Bad Command");
		}
	};

	class AssertError : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Bad Assertion");
		}
	};

	class AddError : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Add Error");
		}
	};

	class Overflow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Overflow");
		}
	};

	class Underflow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Underflow");
		}
	};

	class NotANumber : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Not-A-Number");
		}
	};

	class Infinite : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Infinite");
		}
	};

	class BadType : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("BadType");
		}
	};

	class ValueOfZero : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Value of zero");
		}
	};

	class WTF : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("W.T.F !!!");
		}
	};

	int			getValue() const;
	void		empty();

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, Exception &c);
