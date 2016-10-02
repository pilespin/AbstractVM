/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:09:43 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/02 19:53:15 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <project.hpp>

#define REGEX_IF_COMMAND_EXIST 			"push|pop|dump|assert|add|sub|mul|div|mod|print|exit"
#define REGEX_IF_WITHOUT_ARGUMENT 		"^\\s*(pop|dump|add|sub|mul|div|mod|print|exit)\\s*$"
#define REGEX_CHECK_IF_IS_VALID_INT		"^\\s*(push|assert)\\s+(int8|int16|int32)\\s*\\(\\s*([0-9]*)\\s*\\)\\s*$"
#define REGEX_CHECK_IF_IS_VALID_FLOAT	"^\\s*(push|assert)\\s+(float|double)\\s*\\((\\s*[0-9]*\\.[0-9]*\\s*)\\)\\s*$"
#define REGEX_GET_TYPE					"int8|int16|int32|float|double"
#define REGEX_GET_VALUE_INT				"\\(\\s*([0-9]*)\\s*\\)"
#define REGEX_GET_VALUE_FLOAT			"\\(\\s*([0-9]*\\.[0-9]*)\\s*\\)"
#define REGEX_GET_COMMAND				"push|pop|dump|assert|add|sub|mul|div|mod|print|exit"

class Parse {

public:
	Parse();
	~Parse();
	Parse(Parse const &src);
	Parse &operator=(Parse const &rhs);

	void		readFile(std::string filename);

	int			getValue() const;
	void		empty();

private:
	int _val;
};

std::ostream &operator<<(std::ostream &o, Parse &c);