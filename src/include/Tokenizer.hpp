/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_TOKENIZER_HPP
#define ALB_TOKENIZER_HPP

#include <cstdint>
#include <vector>
#include "Token.hpp"

namespace alb_lang {
  /**
   * Performs tokenization of input data (parsing the text).
   */
  class Tokenizer {
  public:
    /**
     * Tokenizes input data in \c utf8Data, appending them to \c tokenList
     * @param utf8Data Pointer to the beginning of the block of data
     * @param dataSize Complete size of the data
     * @param tokenList Reference to vector to append the tokens to.
     */
    static void tokenizeUTF8(char* utf8Data, uint64_t dataSize, std::vector<Token>& tokenList);
  };

  void Tokenizer::tokenizeUTF8(char *utf8Data, uint64_t dataSize, std::vector<alb_lang::Token> &tokenList) {

  }
}

#endif //ALB_TOKENIZER_HPP
