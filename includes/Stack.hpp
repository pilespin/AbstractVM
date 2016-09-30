
#pragma once

#include <project.hpp>
#include "IOperand.hpp"

class Stack {

public:
	Stack();
	~Stack();
	Stack(Stack const &src);
	// Stack &operator=(Stack const &rhs);

	void	push(IOperand const *);
	void	dump();

	int								getValue() const;
	std::list<IOperand const *>		getList() const;
	void							empty();

private:
	int							_val;
	std::list<IOperand const *>	list;
};

std::ostream &operator<<(std::ostream &o, Stack &c);
