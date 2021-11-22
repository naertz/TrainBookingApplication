#include "linked_bogies_empty_exception.h"

/****************/
/* Constructors */
/****************/

LinkedBogiesEmptyException::LinkedBogiesEmptyException(void)
  : message("Linked bogies list is empty.") { }

LinkedBogiesEmptyException::LinkedBogiesEmptyException(std::string const &message)
  : message(message) { }

/*************/
/* Accessors */
/*************/

const char *LinkedBogiesEmptyException::what(void) const noexcept {
	return message.c_str();
}
