/*
	Program class and reserved keywords
	The ALB Programming Language
	Alberto Navalon Lillo (C) 2019

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

using namespace alb_statement;

namespace alb_program{
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
			void readSource(const std::string& fileName){ // Read source code into vector
				ifstream source; // source file
				std::string holder; // to hold the value of the current token

				source.open(fileName.c_str(), ios::in); // Open file in read mode

				// Now, we will read the file until we reach the end
				while(!source.eof()){
					// Complete here
				}

				source.close();
			} // void readSource()
			// This function can be executed slowly, specially in large files
	};

	void Program::readSource(const std::string& fileName){
		ifstream source; // File
		source.open(fileName.c_str(), ios::in); // Open file in read mode (allowing input)

		// Now, we will read the file until it finishes
		while(!source.eof()){

		}

		source.close(); // Close file
	} // void Program::readSource()
	/*

		TODO:
			- Complete loop in readSource() so it reads every token and stores it with its corresponding attributes (level, type) in the vector statements

	*/
} // alb_program

#endif // ALB_PROGRAM_HPP
