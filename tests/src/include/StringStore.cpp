/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include <gtest/gtest.h>
#include <include/StringStore.hpp>

TEST(stringStore_tests, stringStore_tests_constructor_Test) {
  ASSERT_NO_THROW(alb_lang::StringStore{});
}

TEST(stringstore_tests, stringstore_tests_counter_incrementation_Test) {
  alb_lang::StringStore stringStore {};
  ASSERT_EQ(stringStore.getStringLiteralCount(), 0);
  stringStore.storeString("test");
  ASSERT_EQ(stringStore.getStringLiteralCount(), 1);
}