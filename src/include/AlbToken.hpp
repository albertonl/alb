/*
	Program class and reserved keywords
	The ALB Programming Language
	Alberto Navalon Lillo (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_ALBTOKEN_HPP
#define ALB_ALBTOKEN_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

namespace alb_lang {
  class Token {
  public:
    virtual const std::string& getTextContents() const = 0;
  };
}

#endif //ALB_ALBTOKEN_HPP
