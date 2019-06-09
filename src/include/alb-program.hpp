/*
	Program class and reserved keywords
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
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

namespace alb_lang{
	// Reserved keywords
	enum keywords{
		GENERAL,
		BEGIN,END
	};

	// Program class
	class Program{
		private:
			std::vector<Statement> statements;
		public:
			Program() = default; // Void constructor
			void readSource(const std::string& fileName){} // Read source code into vector
			// This function can be executed slowly, specially in large files
	};

	/*

		TODO:
			- Create readSource() function (it must read insert every token in the file into separate locations in the vector, in the order they appear in the source file)

	*/
} // alb_lang

#endif // ALB_PROGRAM_HPP
