/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:09:43 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/08 18:10:35 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Parse.hpp"

Parse::Parse() {	
	this->_val = 0;
	this->lineError = 0;
	this->factory = Factory();

}

Parse::Parse(Stack *s) {	
	this->_val = 0;
	this->lineError = 0;
	this->stack = s;
	this->factory = Factory();

	this->strToIoperand["int8"] = eOperandType::Int8;
	this->strToIoperand["int16"] = eOperandType::Int16;
	this->strToIoperand["int32"] = eOperandType::Int32;
	this->strToIoperand["float"] = eOperandType::Float;
	this->strToIoperand["double"] = eOperandType::Double;

	this->strToIoperator["add"] = eOperatorType::Add;
	this->strToIoperator["mul"] = eOperatorType::Mul;
	this->strToIoperator["sub"] = eOperatorType::Sub;
	this->strToIoperator["div"] = eOperatorType::Div; 
	this->strToIoperator["mod"] = eOperatorType::Mod;
}

Parse::~Parse()					{}

Parse::Parse(Parse const &src)	{	*this = src;	}

Parse	&Parse::operator=(Parse const &rhs) {

	if (this != &rhs)
	{
		this->_val = rhs._val;
		this->lineError = rhs.lineError;
		this->stack = rhs.stack;
		this->factory = rhs.factory;
		this->userInput = rhs.userInput;
		this->command = rhs.command;
		this->type = rhs.type;
		this->value = rhs.value;
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
		if (!std::getline(std::cin, in))
			return;
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

	this->lineError++;
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
		this->parseLine(line);
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

void	Parse::parseLine(std::string line) {

	std::string error;
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
			throw Error("Line " + std::to_string(this->lineError) + ": " + "Syntax error");
		}
		this->execute();
	}
	else
	{
		throw Error("Line " + std::to_string(this->lineError) + ": " + "This command not exist");
	}
}


void	Parse::execute() {

	if (!this->command.compare("push"))
	{
		IOperand const *one = factory.createOperand(stringToIOperandType(this->type), this->value);
		this->stack->push(one);
	}
	else if (!this->command.compare("assert"))
		this->stack->assert(this->value, this->strToIoperand[this->type]);
	else if (!this->command.compare("pop"))
		this->stack->pop();
	else if (!this->command.compare("dump"))
		this->stack->dump();
	else if (!this->command.compare("print"))
		this->stack->print();
	else if (!this->command.compare("exit"))
		this->stack->exit();
	else if (!this->command.compare("add") || !this->command.compare("mul") || 
		!this->command.compare("div") || !this->command.compare("sub") ||
		!this->command.compare("mod"))
	{
		this->stack->operate(this->stringToIOperatorType(this->command));
	}
	else
		throw Error("WTF1");

}

eOperandType	Parse::stringToIOperandType(std::string type) {

	return (strToIoperand[type]);

}

eOperatorType	Parse::stringToIOperatorType(std::string type) {

	return (strToIoperator[type]);

}

void	Parse::empty() {

}
