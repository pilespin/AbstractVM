/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:24:46 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/04 20:13:33 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <project.hpp>
#include "Exception.hpp"
#include "IOperand.hpp"

class Stack : public Exception {

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
	void				print();
	void				exit();

	int					getValue() const;
	void				checkExit() const;

private:
	bool 						goodExit;
	int							_val;
	std::list<IOperand const *>	list;
};

std::ostream &operator<<(std::ostream &o, Stack &c);
