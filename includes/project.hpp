/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 18:48:50 by pilespin          #+#    #+#             */
/*   Updated: 2016/09/30 16:06:34 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum eOperandType {Int8, Int16, Int32, Float, Double};

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cfloat>
#include <vector>

#define PRECISION_INT8 	static_cast<int>(eOperandType::Int8)
#define PRECISION_INT16 static_cast<int>(eOperandType::Int16)
#define PRECISION_INT32 static_cast<int>(eOperandType::Int32)
#define PRECISION_FLT 	static_cast<int>(eOperandType::Float)
#define PRECISION_DBL 	static_cast<int>(eOperandType::Double)
