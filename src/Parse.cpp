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

void	Parse::readFile() {

	std::string line;
	std::smatch res;
	int		pos;

	// trim(line);

	// std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	if (this->file.is_open())
	{
		while (getline(this->file, line))
		{
			std::cout << "full: " << line << std::endl;
			pos = line.find(";");
			if (!pos)
				continue;
			else
				line = line.substr(0, pos);

			std::cout << " cut: " << line << std::endl;

			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_IF_COMMAND_EXIST)))
			{
				if (std::regex_search(line, res, static_cast<std::regex>(REGEX_IF_WITHOUT_ARGUMENT)))
				{
					this->command = res.str();
					this->type = "";
					this->value = "";
				}
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
					continue;
				}
				std::cout << "command: " << this->command << " type: " << this->type << " value: " << this->value << std::endl << std::endl;
			}
			else
				std::cout << "Bad command" << std::endl;
		}
		this->file.close();
	}
	else
		std::cout << "Please call openFile before" << std::endl;

	// std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	// std::cout << "It took me " << time_span.count() << " seconds." << std::endl;

	this->stack->dump();

}

void	Parse::empty() {

}
