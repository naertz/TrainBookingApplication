#include "linked_bogies_out_of_range_exception.h"

/****************/
/* Constructors */
/****************/

LinkedBogiesOutOfRangeException::LinkedBogiesOutOfRangeException(void)
  : message("Index for linked bogies list is out of range.") { }

LinkedBogiesOutOfRangeException::LinkedBogiesOutOfRangeException(std::string const &message)
  : message(message) { }

/*************/
/* Accessors */
/*************/

const char *LinkedBogiesOutOfRangeException::what(void) const noexcept {
	return message.c_str();
}
