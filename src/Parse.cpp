/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:09:43 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/02 19:53:53 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"

Parse::Parse()					{	this->_val = 0;	}

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
void	Parse::readFile(std::string filename) {

	std::ifstream f;
	std::string line;

	std::smatch res;

	f.open(filename);

	if (f.is_open())
	{
		while (getline(f, line))
		{
			std::cout << line << std::endl;
			if (std::regex_search(line, res, static_cast<std::regex>(REGEX_IF_COMMAND_EXIST)))
			{
				if (std::regex_search(line, res, static_cast<std::regex>(REGEX_IF_WITHOUT_ARGUMENT)))
				{
					std::cout << "IS VALID " << res.str() << std::endl;
					std::cout << std::endl;
				}
				else if (std::regex_search(line, res, static_cast<std::regex>(REGEX_CHECK_IF_IS_VALID_INT)))
				{
					if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_COMMAND)))
					{
						std::cout << "command: " << res.str() << " ";
					}
					if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_TYPE)))
					{
						std::cout << "type: " << res.str() << " ";
					}
					if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_VALUE_INT)))
					{
						std::cout << "value: " << res[1].str() << " " << std::endl;
					}
					std::cout << "IS VALID " << std::endl;
					std::cout << std::endl;
				}
				else if (std::regex_search(line, res, static_cast<std::regex>(REGEX_CHECK_IF_IS_VALID_FLOAT)))
				{
					if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_COMMAND)))
					{
						std::cout << "command: " << res.str() << " ";
					}
					if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_TYPE)))
					{
						std::cout << "type: " << res.str() << " ";
					}
					if (std::regex_search(line, res, static_cast<std::regex>(REGEX_GET_VALUE_FLOAT)))
					{
						std::cout << "value: " << res[1].str() << " " << std::endl;
					}
					std::cout << "IS VALID " << " " << std::endl;
					std::cout << std::endl;
				}
				else
					std::cout << "Syntax error" << std::endl;
			}
			else
				std::cout << "Bad command" << std::endl;
		}
		f.close();
	}
	else
		std::cout << "Unable to open file";

}

void	Parse::empty() {

}
