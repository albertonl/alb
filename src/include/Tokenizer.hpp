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
  private:
    /**
     * Returns true if codepoint passed represents a valid whitespace character.
     *
     * Valid whitespace character codepoints are:
     * - U+0009 (tab)
     * - U+000A (LF)
     * - U+000B (VT)
     * - U+000C (FF)
     * - U+000D (CR)
     * - U+0020 (space)
     * - U+0085 (unicode NEXT LINE)
     * - U+00A0 (nbsp)
     * - U+1680 (Ogham space)
     * - U+2000 (en space, variant 1)
     * - U+2001 (em space, variant 1)
     * - U+2002 (en space, variant 2)
     * - U+2003 (em space, variant 2)
     * - U+2004 (one third of em space)
     * - U+2005 (one fourth of em space)
     * - U+2006 (one sixth of em space)
     * - U+2007 (figure space)
     * - U+2008 (punctuation space)
     * - U+2009 (thin space)
     * - U+200A (hair space)
     * - U+2028 (line separator)
     * - U+2029 (paragraph separator)
     * - U+202F (narrow nbsp)
     * - U+205F (medium mathspace)
     * - U+3000 (some other space)
     * - U+200B (zero width space)
     * - U+2060 (word joiner (zero width nbsp))
     * - U+FEFF (deprecated zero width nbsp)
     *
     * Also, this method returns true for some technically non-whitespace
     * characters, which are however included if only just for fun:
     * - U+00B7 (interpunct - · )
     * - U+237D (visual representation of nbsp - ⍽ )
     * - U+2420 (symbol for space - ␠ )
     * - U+2422 (symbol for blank - ␢ )
     * - U+2423 (handwriting symbol for space - ␣ )
     *
     * @param codepoint The unicode codepoint for which to check for whitespaceness.
     * @return true when the character is whitespace from the upper list
     */
    constexpr bool isCharacterWhitespace(uint32_t codepoint);
  public:
    Tokenizer() = default;
    /**
     * Tokenizes input data in \c utf8Data, appending them to \c tokenList
     * @param utf8Data Pointer to the beginning of the block of data
     * @param dataSize Complete size of the data
     * @param tokenList Reference to vector to append the tokens to.
     */
    static void tokenizeUTF8(char* utf8Data, uint64_t dataSize, std::vector<Token>& tokenList) noexcept(false);
  };

  void Tokenizer::tokenizeUTF8(char *utf8Data, uint64_t dataSize, std::vector<alb_lang::Token> &tokenList) {

  }
}

#endif //ALB_TOKENIZER_HPP
