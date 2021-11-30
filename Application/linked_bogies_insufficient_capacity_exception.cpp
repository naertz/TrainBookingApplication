#include "linked_bogies_insufficient_capacity_exception.h"

/****************/
/* Constructors */
/****************/

LinkedBogiesInsufficientCapacityException::LinkedBogiesInsufficientCapacityException(void)
  : message("There is an insufficient amount of seats available.") { }

LinkedBogiesInsufficientCapacityException::LinkedBogiesInsufficientCapacityException(std::string const &message)
  : message(message) { }

/*************/
/* Accessors */
/*************/

const char *LinkedBogiesInsufficientCapacityException::what(void) const noexcept {
	return message.c_str();
}
