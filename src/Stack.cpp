
#include "Stack.hpp"

Stack::Stack() 						{	this->_val = 0;	}

Stack::~Stack()						{}

Stack::Stack(Stack const &src)	{	*this = src;	}

// Stack	&Stack::operator=(Stack const &rhs) {

// 	if (this != &rhs)
// 	{
// 		this->_val = rhs._val;
// 	}
// 	return (*this);
// }

std::ostream &operator<<(std::ostream &o, Stack &c) {
	o << "Stack: " << c.getValue() << " ";
	return (o);
}

///////////////////////////////////////////////////////////////////////////////
int							Stack::getValue() 	const	{	return (this->_val);	}
std::list<IOperand const *>	Stack::getList() 	const	{	return (this->list);	}
///////////////////////////////////////////////////////////////////////////////

void	Stack::push(IOperand const *value) {

	std::list<IOperand const *> list;

	list = this->list;
	list.push_front(value);
    std::cout << "Push OK" << std::endl;

}

void	Stack::dump() {

	std::list<IOperand const *> list;

	list = this->list;

    std::cout << "Stack:" << std::endl;
  	for (std::list<IOperand const *>::iterator it = list.begin(); it != list.end(); ++it)
    	std::cout << "1" << ' ' << *it << std::endl;

}

void	Stack::empty() {

}
