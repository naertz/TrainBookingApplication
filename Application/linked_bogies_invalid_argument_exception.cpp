#include "linked_bogies_invalid_argument_exception.h"

/****************/
/* Constructors */
/****************/

LinkedBogiesInvalidArgumentException::LinkedBogiesInvalidArgumentException()
  : message("Argument for linked bogies list is invalid.") { }

LinkedBogiesInvalidArgumentException::LinkedBogiesInvalidArgumentException(std::string const &message)
  : message(message) { }

/*************/
/* Accessors */
/*************/

const char *LinkedBogiesInvalidArgumentException::what(void) const noexcept {
	return message.c_str();
}
