/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_COMPILERDIRECTIVECHECKS_HPP
#define ALB_COMPILERDIRECTIVECHECKS_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <absl/strings/str_split.h>

namespace alb_lang {

  /**
   * Asserts that the string passed in represents a valid compiler directive,
   * i.e. begins with `::`
   * @param directive The string to check on
   * @throws std::runtime_error on failure
   */
  void assertDirectiveIsValidDirective(const std::string &directive) noexcept(false);

  /**
   * Asserts that a string split by `::` passed in in the vector represents
   * a valid compiler directive, i.e. begins with `::`
   * @param directiveParts The split string to check on
   * @throws std::runtime_error on failure
   */
  void assertDirectiveIsValidDirective(const std::vector<std::string> &directiveParts) noexcept(false);

  /**
   * Asserts that the string passed in represents an internal compiler directive,
   * i.e. begins with `::internal`
   * @param directive The string to check on
   * @throws std::runtime_error on failure
   */
  void assertDirectiveIsInternal(const std::string &directive) noexcept(false);

  /**
   * Asserts that a string split by `::` passed in in the vector represents
   * an internal compiler directive, i.e. begins with `::internal`
   * @param directiveParts The split string to check on
   * @throws std::runtime_error on failure
   */
  void assertDirectiveIsInternal(const std::vector<std::string> &directiveParts) noexcept(false);

  //----------------------------------------------------------------------------
  // Implementations below this point
  //----------------------------------------------------------------------------

  void assertDirectiveIsValidDirective(const std::string &directive) noexcept(false) {
    assertDirectiveIsValidDirective(absl::StrSplit(directive, "::", absl::AllowEmpty{}));
  }

  void assertDirectiveIsValidDirective(const std::vector<std::string> &directiveParts) noexcept(false) {
    // size check disallows size of 1 too - empty string split by `::` would
    // still have one element in the vector of zero width, but still would not be
    // a valid compiler directive
    if (directiveParts.size() < 2 || !directiveParts[0].empty()) {
      throw (std::runtime_error{
          "Given string is not a valid compiler directive (compiler directives must begin with `::`)"});
    }
  }

  void assertDirectiveIsInternal(const std::string &directive) noexcept(false) {
    assertDirectiveIsInternal(absl::StrSplit(directive, "::", absl::AllowEmpty{}));
  }

  void assertDirectiveIsInternal(const std::vector<std::string> &directiveParts) noexcept(false) {
    assertDirectiveIsValidDirective(directiveParts);
    // size check disallows size of 2 too - string `::internal` on its own is
    // still not a valid internal compiler directive
    if (directiveParts.size() < 3 || directiveParts[1] != "internal") {
      throw (std::runtime_error{
          "Given string is not a valid compiler directive (compiler directives must begin with `::`)"});
    }
  }

}
#endif //ALB_COMPILERDIRECTIVECHECKS_HPP
