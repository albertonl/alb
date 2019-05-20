#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

#include "include/alb-statement.hpp" // Statement structure
#include "include/alb-program.hpp" // Program class and reserved keywords
using namespace std;
using namespace alb_statement;
using namespace alb_program;

int main(int argc, char const *argv[]){
	Program program;
	const string fileName = argv[1];

	//program.readSource(fileName); // Still not implemented

	return 0;
}