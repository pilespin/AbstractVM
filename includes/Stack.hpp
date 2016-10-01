/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:24:46 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/01 21:41:17 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <project.hpp>
#include "IOperand.hpp"

class Stack {

public:
	Stack();
	~Stack();
	Stack(Stack const &src);
	// Stack &operator=(Stack const &rhs);

	IOperand const *	getAndPopOnStack();
	void				operateCore(eOperatorType op);
	void				push(IOperand const *);
	void				pop();
	void				dump();
	void				assert(std::string value);
	void				operate(eOperatorType op);

	int								getValue() const;
	std::list<IOperand const *>		getList() const;
	void							empty();

	class EmptyStack : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Empty Stack");
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
			return ("Overflow2");
		}
	};

	class Underflow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Underflow2");
		}
	};

	class NotANumber : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Not-A-Number");
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

private:
	int							_val;
	std::list<IOperand const *>	list;
};

std::ostream &operator<<(std::ostream &o, Stack &c);
