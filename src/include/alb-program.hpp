/*
	Program class and reserved keywords
	The ALB Programming Language
	Alberto Navalon Lillo (C) 2019

	This software is under the GNU General Public License v3.0
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_PROGRAM_HPP
#define ALB_PROGRAM_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

#include "alb-statement.hpp" // Program class and reserved keywords

using namespace std;
using namespace alb_statement;

namespace alb_program{
	// Reserved keywords
	enum keywords{
		GENERAL,
		BEGIN,END
	}

	// Program class
	class Program{
		private:
			std::vector<Statement> statements;
		public:
			Program(){} // Void constructor
			void readSource(const string fileName); // Read source code into vector
			// This function can be executed slowly, specially in large files
	};

	/*

		TODO:
			- Create readSource() function (it must read insert every token in the file into separate locations in the vector, in the order they appear in the source file)

	*/
} // alb_program

#endif // ALB_PROGRAM_HPP
