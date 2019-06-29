/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#include "CompilerDirectiveChecks.hpp"
#include <absl/strings/str_split.h>

void alb_lang::assertDirectiveIsValidDirective(const std::string &directive) noexcept(false) {
  assertDirectiveIsValidDirective(absl::StrSplit(directive, "::", absl::AllowEmpty{}));
}

void alb_lang::assertDirectiveIsValidDirective(const std::vector<std::string> &directiveParts) noexcept(false) {
  // size check disallows size of 1 too - empty string split by `::` would
  // still have one element in the vector of zero width, but still would not be
  // a valid compiler directive
  if (directiveParts.size() < 2 || !directiveParts[0].empty()) {
    throw (std::runtime_error{
        "Given string is not a valid compiler directive (compiler directives must begin with `::`)"});
  }
}

void alb_lang::assertDirectiveIsInternal(const std::string &directive) noexcept(false) {
  assertDirectiveIsInternal(absl::StrSplit(directive, "::", absl::AllowEmpty{}));
}

void alb_lang::assertDirectiveIsInternal(const std::vector<std::string> &directiveParts) noexcept(false) {
  assertDirectiveIsValidDirective(directiveParts);
  // size check disallows size of 2 too - string `::internal` on its own is
  // still not a valid internal compiler directive
  if (directiveParts.size() < 3 || directiveParts[1] != "internal") {
    throw (std::runtime_error{
        "Given string is not a valid compiler directive (compiler directives must begin with `::`)"});
  }
}
