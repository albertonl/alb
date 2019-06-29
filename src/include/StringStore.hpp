/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_STRINGSTORE_HPP
#define ALB_STRINGSTORE_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <absl/strings/str_split.h>
#include <absl/strings/numbers.h>
#include "CompilerDirectiveChecks.hpp"

namespace alb_lang {
  /**
   * Provides a storage for all string literals in compilation target.
   */
  class StringStore {
  private:
    std::vector<std::string> strings {};
  public:
    /**
     * Returns the amount of currently stored string literals.
     *
     * @return The amount of string literals.
     */
    int getStringLiteralCount() const;
    /**
     * Stores a string in this storage.
     *
     * The returned id can be then used for querying the string again anytime later.
     *
     * @param s String to store.
     * @return The newly assigned global id of the stored string literal.
     */
    std::string storeString(const std::string& s);
    /**
     * Returns the string literal stored under specific id.
     *
     * @param id The id for the string literal, as returned by \c storeString
     * @return The actual string literal
     */
    std::string getString(const std::string& id) const;
  };

  std::string StringStore::storeString(const std::string& s) {
    strings.push_back(s);
    return "::internal::strings::" + std::to_string(strings.size() - 1);
  }

  int StringStore::getStringLiteralCount() const {
    return strings.size();
  }

  std::string StringStore::getString(const std::string& id) const {
    std::vector<std::string> strParts = absl::StrSplit(id, "::");
    assertDirectiveIsInternal(strParts);
    long numStringId = 0;
    if (strParts.size() < 4 || strParts[2] != "strings" || !absl::SimpleAtoi(strParts[3], &numStringId)) {
      throw (std::runtime_error{
        "Given string is not a valid string identifier"
      });
    }
    return strings[numStringId];
  }
}

#endif //ALB_STRINGSTORE_HPP
