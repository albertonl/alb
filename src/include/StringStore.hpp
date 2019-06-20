/*
	The ALB Programming Language
	Alb Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_STRINGSTORE_HPP
#define ALB_STRINGSTORE_HPP

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
  };
}

#endif //ALB_STRINGSTORE_HPP
