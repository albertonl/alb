/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_LEXER_HPP
#define ALB_LEXER_HPP

#include <cstdint>
#include <vector>
#include "Token.hpp"
#include <stdexcept>

namespace alb_lang {
  /**
   * Performs lexical analysis of input data (parsing the text).
   */
  class Lexer {
  private:
    /**
     * Returns true if codepoint passed represents a valid whitespace character.
     *
     * Valid whitespace character codepoints are:
     * - U+0000 (NULL)
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
    static constexpr bool isCharacterWhitespace(uint32_t codepoint) noexcept ;
    /**
     * Returns true if codepoint passed represents a valid newline character.
     *
     * Valid newline character codepoints are:
     * - U+000A (LF)
     * - U+000B (VT)
     * - U+000C (FF)
     * - U+000D (CR)
     * - U+0085 (unicode NEXT LINE)
     * - U+2028 (line separator)
     * - U+2029 (paragraph separator)
     *
     * @param codepoint The unicode codepoint which to check
     * @return true when the character is newline from the upper list
     */
    static constexpr bool isCharacterNewline(uint32_t codepoint) noexcept ;
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
    static constexpr bool isCharacterSpecialMeaning(uint32_t codepoint) noexcept ;
    /**
     * Returns next character as unicode codepoint from the block of input data.
     * @param utf8Data Block of UTF-8 input data.
     * @param currindex The index of the first byte of the next character
     * @return The next character as unicode codepoint
     */
    static uint32_t getNextChar(unsigned char* utf8Data, uint64_t& currindex) noexcept(false);
  public:
    Lexer() = default;
    /**
     * Performs lexical analysis of input data in \c utf8Data, appending them to \c tokenList
     * @param utf8Data Pointer to the beginning of the block of data
     * @param dataSize Complete size of the data
     * @param tokenList Reference to vector to append the tokens to.
     */
    static void tokenizeUTF8(char* utf8Data, uint64_t dataSize, std::vector<Token*>& tokenList) noexcept(false);
  };

  constexpr bool Lexer::isCharacterWhitespace(uint32_t codepoint) noexcept {
    switch (codepoint) {
      case 0x0000:
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

  constexpr bool Lexer::isCharacterNewline(uint32_t codepoint) noexcept {
    switch (codepoint) {
      case 0x000A:
      case 0x000B:
      case 0x000C:
      case 0x000D:
      case 0x0085:
      case 0x2028:
      case 0x2029:
        return true;
      default:
        return false;
    }
  }

  constexpr bool Lexer::isCharacterSpecialMeaning(uint32_t codepoint) noexcept {
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

  uint32_t Lexer::getNextChar(unsigned char *utf8Data, uint64_t &currindex) noexcept(false) {
    if (((utf8Data[currindex]) & 0b10000000u) == 0) {
      return utf8Data[currindex++];
    }
    if ((utf8Data[currindex] & 0b11100000u) == 0b11000000) {
      const uint32_t firstByteBits = utf8Data[currindex++] & 0b00011111u;
      const uint32_t secondByteBits = utf8Data[currindex++] & 0b00111111u;
      return (firstByteBits << 6u) + secondByteBits;
    }
    if ((utf8Data[currindex] & 0b11110000u) == 0b11100000) {
      const uint32_t firstByteBits = utf8Data[currindex++] & 0b00001111u;
      const uint32_t secondByteBits = utf8Data[currindex++] & 0b00111111u;
      const uint32_t thirdByteBits = utf8Data[currindex++] & 0b00111111u;
      return (firstByteBits << 12u) + (secondByteBits << 6u) + thirdByteBits;
    }
    if ((utf8Data[currindex] &0b11111000u) == 0b11110000u) {
      const uint32_t firstByteBits = utf8Data[currindex++] & 0b00000111u;
      const uint32_t secondByteBits = utf8Data[currindex++] & 0b00111111u;
      const uint32_t thirdByteBits = utf8Data[currindex++] & 0b00111111u;
      const uint32_t fourthByteBits = utf8Data[currindex++] & 0b00111111u;
      return (firstByteBits << 18u) + (secondByteBits << 12u) + (thirdByteBits << 6u) + fourthByteBits;
    }
    throw std::runtime_error{"Invalid UTF-8 data."};
  }

  void Lexer::tokenizeUTF8(char *utf8Data, uint64_t dataSize, std::vector<Token*> &tokenList) {
    uint64_t startindex=0, endindex= 0, currindex = 0;
    while (currindex < dataSize) {
      endindex = currindex - 1;
      uint32_t nextChar = getNextChar((unsigned char*)(utf8Data), currindex);
      if (isCharacterWhitespace(nextChar) || isCharacterSpecialMeaning((nextChar))) {
        if (!(endindex < startindex || endindex == UINT64_MAX)) {
          tokenList.push_back(new BasicToken{std::string{(char *) utf8Data + startindex, endindex - startindex + 1}});
        }
        startindex = currindex;
        if (isCharacterSpecialMeaning(nextChar)) {


          // Handle comments in code
          if (nextChar == '/') {
            if (currindex < dataSize) {
              uint64_t tempCurrindex = currindex;
              uint32_t nextNextChar = getNextChar((unsigned char*)(utf8Data), tempCurrindex);
              if (nextNextChar == '/' || nextNextChar == '*') {
                getNextChar((unsigned char*)utf8Data, currindex); // To get currindex past nextNextChar
                while (currindex < dataSize) {
                  uint32_t nextInCommentChar = getNextChar((unsigned char*)utf8Data, currindex);
                  if (nextNextChar == '/' && isCharacterNewline(nextInCommentChar)) {
                    break;
                  } else if (nextNextChar == '*' && nextInCommentChar == '*') {
                    uint64_t anotherTempCurrIndex = currindex;
                    uint32_t nextNextInCommentChar = getNextChar((unsigned char*) utf8Data, anotherTempCurrIndex);
                    if (nextNextInCommentChar == '/') {
                      break;
                    }
                  }
                }
                startindex = currindex;
                continue;
              }
            }
          }


          tokenList.push_back(new BasicToken{std::string{(char)nextChar}});
        }
      }
    }
  }
}

#endif //ALB_LEXER_HPP
