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
}
#endif //ALB_COMPILERDIRECTIVECHECKS_HPP
