/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_TOKEN_HPP
#define ALB_TOKEN_HPP

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
  /**
   * Tokens are the smallest pieces of data extractable from alb source code.
   *
   * Example tokens are single keyword, literal, math symbol etc.
   */
  class Token {
  public:
    /**
     * Returns the actual piece of alb source code this token represents.
     *
     * Is returned as const ref for possibility of speed optimizations.
     * When additional modification of returned text is required, caller must
     * manually copy the string, or respective implementor must provide other
     * means to be used.
     *
     * @return The text contents itself.
     */
    virtual const std::string& getTextContents() const = 0;
  };
}

#endif //ALB_TOKEN_HPP
