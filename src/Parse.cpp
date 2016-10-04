/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:09:43 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/04 19:38:07 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Parse.hpp"

Parse::Parse() {	
	this->_val = 0;
	this->factory = Factory();

}

Parse::Parse(Stack *s) {	
	this->_val = 0;
	this->stack = s;
	this->factory = Factory();
}

Parse::~Parse()					{}

Parse::Parse(Parse const &src)	{	*this = src;	}

Parse	&Parse::operator=(Parse const &rhs) {

	if (this != &rhs)
	{
		this->_val = rhs._val;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Parse &c) {
	o << "Parse: " << c.getValue() << " ";
	return (o);
}
///////////////////////////////////////////////////////////////////////////////
int		Parse::getValue() const	{	return (this->_val);	}
///////////////////////////////////////////////////////////////////////////////

void	Parse::openFile(std::string filename) {
	this->file.open(filename);
	if (!this->file.is_open())
	{
		std::cout << "Unable to open file: " << filename << std::endl;
	}

}

static std::string trim(std::string str)
{
	int st;
	int end;

	st = str.find_first_not_of(" 	");
	end = str.find_last_not_of(" 	");

	if ((end > -1 && st > -1))
		return (str.substr(st, (end - st) + 1));
	else
		return ("");
}

void	Parse::readFromUser() {

	while (1)
	{
		std::string in;

		std::cout << "> ";
		std::getline(std::cin, in);

		if (!in.compare(";;"))
		{
			this->readFileUser();
			return;
		}
		this->userInput += in + "\n";
	}

}

void 	Parse::cleanAndParse(std::string line) {

	int			pos;

	this->command = "";
	this->type = "";
	this->value = "";
	pos = line.find(";");
	if (!pos)
		return;
	else
		line = line.substr(0, pos);
	line = trim(line);
	if (line.length())
	{
		this->parseLine(line, TRUE);
	}

}


void	Parse::readFileUser() {

	std::string line;

	std::istringstream stream(this->userInput);

	while (getline(stream, line))
	{
		this->cleanAndParse(line);
	}

}

void	Parse::readFile() {

	std::string line;

	if (this->file.is_open())
	{
		while (getline(this->file, line))
		{
			this->cleanAndParse(line);
		}
		this->file.close();
	}
	else
		std::cerr << "Please call openFile before" << std::endl;

}

void	Parse::parseLine(std::string line, bool wantExcept) {

	std::smatch res;

	if (std::regex_search(line, res, static_cast<std::regex>(REGEX_IF_COMMAND_EXIST)))
	{
		if (std::regex_search(line, res, static_cast<std::regex>(REGEX_IF_WITHOUT_ARGUMENT)))
			this->command = res.str();
		else if (std::regex_search(line, res, static_cast<std::regex>(REGEX_CHECK_IF_IS_VALID_INT)))
		{
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_COMMAND)))
				this->command = res.str();
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_TYPE)))
				this->type = res.str();
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_VALUE_INT)))
				this->value = res[1].str();
		}
		else if (std::regex_search(line, res, static_cast<std::regex>(REGEX_CHECK_IF_IS_VALID_FLOAT)))
		{
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_COMMAND)))
				this->command = res.str();
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_TYPE)))
				this->type = res.str();
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_VALUE_FLOAT)))
				this->value = res[1].str();
		}
		else
		{
			if (wantExcept)
				throw SyntaxError();
			else
			{
				std::cerr << "Syntax error" << std::endl;
				return;
			}
		}
		this->execute();
	}
	else
	{
		if (wantExcept)
			throw BadCommand();
		else
			std::cerr << "Bad command" << std::endl;
	}
}


void	Parse::execute() {

	if (!this->command.compare("push"))
	{
		IOperand const *one = factory.createOperand(stringToIOperandType(this->type), this->value);
		this->stack->push(one);
	}
	else if (!this->command.compare("assert"))
		this->stack->assert(this->value);
	else if (!this->command.compare("pop"))
		this->stack->pop();
	else if (!this->command.compare("dump"))
		this->stack->dump();
	else if (!this->command.compare("print"))
		this->stack->print();
	else if (!this->command.compare("exit"))
		this->stack->exit();
	else if (!this->command.compare("add"))
		this->stack->operate(this->stringToIOperatorType(this->command));
	else if (!this->command.compare("mul"))
		this->stack->operate(this->stringToIOperatorType(this->command));
	else if (!this->command.compare("div"))
		this->stack->operate(this->stringToIOperatorType(this->command));
	else if (!this->command.compare("sub"))
		this->stack->operate(this->stringToIOperatorType(this->command));
	else if (!this->command.compare("mod"))
		this->stack->operate(this->stringToIOperatorType(this->command));
	else
		throw WTF();

}

eOperandType	Parse::stringToIOperandType(std::string type) {

	if (!type.compare("int8"))
		return (eOperandType::Int8);
	else if (!type.compare("int16"))
		return (eOperandType::Int16);
	else if (!type.compare("int32"))
		return (eOperandType::Int32);
	else if (!type.compare("float"))
		return (eOperandType::Float);
	else if (!type.compare("double"))
		return (eOperandType::Double);
	else
		throw WTF();

}

eOperatorType	Parse::stringToIOperatorType(std::string type) {

	if (!type.compare("add"))
		return (eOperatorType::Add);
	else if (!type.compare("mul"))
		return (eOperatorType::Mul);
	else if (!type.compare("sub"))
		return (eOperatorType::Sub);
	else if (!type.compare("div"))
		return (eOperatorType::Div);
	else if (!type.compare("mod"))
		return (eOperatorType::Mod);
	throw WTF();

}

void	Parse::empty() {

}
