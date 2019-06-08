/*
	Statement structure
	The ALB Programming Language
	Alberto Navalon Lillo (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_STATEMENT_HPP
#define ALB_STATEMENT_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

namespace alb_statement{

	struct Statement{
		const std::string st; // Literal statement
		const int level; // Informally, the number of tabs by which the statement is preceded
		const int type; // Type of statement (or if it is a reserved keyword)

		Statement(std::string st, int level, int type); // Constructor
	};

	Statement::Statement(std::string st, int level, int type) : st(std::move(st)), level(level), type(type){	}
} // alb_statement

#endif // ALB_STATEMENT_HPP
