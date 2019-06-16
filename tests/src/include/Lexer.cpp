/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include <gtest/gtest.h>
#include <include/Lexer.hpp>

TEST(tokenizer_tests, tokenizer_tests_constructor_Test) {
  ASSERT_NO_THROW(alb_lang::Lexer{});
}

TEST(tokenizer_tests, tokenizer_tests_utf8_parsing_token_count_Test) {
  char testData[] = "BEGIN .\nEND";
  std::vector<alb_lang::Token*> tokens;
  alb_lang::Lexer::tokenizeUTF8(testData, sizeof(testData), tokens);
  ASSERT_EQ(tokens.size(), 3);
}
