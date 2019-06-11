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
    /**
     * Returns true if codepoint passed represents a character with special meaning in alb.
     *
     * These characters are all in the ASCII range, and specifically are:
     * - \c +*-/ for basic math operations
     * - \c = for assignments, also in \c == and variants for comparing
     * - \c (){}[] as ever useful brackets
     * - \c % for modulo operation
     * - \c ?: as "conditional operator" (also known as ternary operator)
     * - \c ;., for generic separating/chaining
     * - \c ^&|<>~ as bitwise operators
     * - \c ! for logical negation
     * - \c "' for marking strings
     *
     * @param codepoint The unicode codepoint for which to check for special meaning.
     * @return true when the character has special meaning assigned
     */
    constexpr bool isCharacterSpecialMeaning(uint32_t codepoint);
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

  constexpr bool Tokenizer::isCharacterWhitespace(uint32_t codepoint) {
    switch (codepoint) {
      case 0x0009:
      case 0x000A:
      case 0x000B:
      case 0x000C:
      case 0x000D:
      case 0x0020:
      case 0x0085:
      case 0x00A0:
      case 0x1680:
      case 0x2000:
      case 0x2001:
      case 0x2002:
      case 0x2003:
      case 0x2006:
      case 0x2004:
      case 0x2005:
      case 0x2007:
      case 0x2008:
      case 0x2009:
      case 0x200A:
      case 0x2028:
      case 0x2029:
      case 0x202F:
      case 0x205F:
      case 0x3000:
      case 0x200B:
      case 0x2060:
      case 0xFEFF:
      case 0x00B7:
      case 0x237D:
      case 0x2420:
      case 0x2422:
      case 0x2423:
        return true;
      default:
        return false;
    }
  }

  constexpr bool Tokenizer::isCharacterSpecialMeaning(uint32_t codepoint) {
    if (codepoint > 127) { // Character is not in ASCII range -> it is not a special meaning char
      return false;
    }
    switch ((uint8_t) codepoint) {
      case '+':
      case '*':
      case '-':
      case '/':
      case '=':
      case '(':
      case ')':
      case '{':
      case '}':
      case '[':
      case ']':
      case '%':
      case '?':
      case ':':
      case ';':
      case '.':
      case ',':
      case '^':
      case '&':
      case '|':
      case '<':
      case '>':
      case '~':
      case '!':
      case '"':
      case '\'':
        return true;
      default:
        return false;
    }
  }
}

#endif //ALB_TOKENIZER_HPP
