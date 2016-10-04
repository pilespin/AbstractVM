/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 18:48:50 by pilespin          #+#    #+#             */
/*   Updated: 2016/10/04 19:30:56 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum eOperandType 	{Int8, Int16, Int32, Float, Double};
enum eOperatorType 	{Add, Sub, Mul, Div, Mod};

#define TRUE 	1
#define FALSE 	0

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include <cfloat>
#include <vector>
#include <list>
#include <limits>
#include <cmath>
#include <ctgmath>
#include <regex>
