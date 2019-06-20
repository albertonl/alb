/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_STRINGSTORE_HPP
#define ALB_STRINGSTORE_HPP

#include <string>

namespace alb_lang {
  /**
   * Provides a storage for all string literals in compilation target.
   */
  class StringStore {
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
    std::string storeString(std::string s);
    /**
     * Returns the string literal stored under specific id.
     *
     * @param id The id for the string literal, as returned by \c storeString
     * @return The actual string literal
     */
    std::string getString(std::string id) const;
  };
}

#endif //ALB_STRINGSTORE_HPP
