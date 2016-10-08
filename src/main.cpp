/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:34:08 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/08 18:31:15 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.hpp>
#include "Factory.hpp"
#include "TNumber.hpp"
#include "Stack.hpp"
#include "Parse.hpp"

int main(int ac, char**av)
{
	try
	{
		Stack *s = new Stack();
		Parse p = Parse(s);

		if (ac > 1)
		{
			std::string file = av[1];
			p.openFile(file);
			p.readFile();
		}
		else
			p.readFromUser();
		s->checkExit();
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}

	return (0);
}
