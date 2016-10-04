/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:09:43 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/03 19:31:35 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Parse.hpp"

Parse::Parse()					{	this->_val = 0;	}

Parse::Parse(Stack *s)					{	
	this->_val = 0;
	this->stack = s;
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

void	Parse::readFile() {

	std::string line;
	int			pos;

	if (this->file.is_open())
	{
		while (getline(this->file, line))
		{
			this->command = "";
			this->type = "";
			this->value = "";
			pos = line.find(";");
			if (!pos)
				continue;
			else
				line = line.substr(0, pos);
			line = trim(line);
			if (line.length())
			{
				this->parseLine(line);
			}
		}
		this->file.close();
	}
	else
		std::cout << "Please call openFile before" << std::endl;
	this->stack->dump();

}

void	Parse::parseLine(std::string line) {

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
			std::cout << "Syntax error" << std::endl;
			return;
		}
		std::cout << "command: " << this->command << " type: " << this->type << " value: " << this->value << std::endl;
		std::cout << std::endl;
		this->execute();
	}
	else
		std::cout << "Bad command" << std::endl;

}

void	Parse::execute() {

	// IOperand const *one = factory.createOperand(ioone, vone);

	// if (!this->command.compare(push))
	// 	this->stack->push()

}

void	Parse::empty() {

}
