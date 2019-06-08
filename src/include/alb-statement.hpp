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

using namespace std;

namespace alb_statement{

	struct Statement{
		const string st; // Literal statement
		const int level; // Informally, the number of tabs by which the statement is preceded
		const int type; // Type of statement (or if it is a reserved keyword)

		Statement(string st, int level, int type); // Constructor
	};

	Statement::Statement(string st, int level, int type) : st(st), level(level), type(type){	}
} // alb_statement

#endif // ALB_STATEMENT_HPP
