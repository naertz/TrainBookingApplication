#include "member.h"

/****************/
/* Constructors */
/****************/

Member::Member(std::string const &first_name, std::string const &last_name)
  : first_name(first_name)
  , last_name(last_name) { }

/*************/
/* Accessors */
/*************/

std::string Member::get_first_name(void) const {
	return first_name;
}

std::string Member::get_last_name(void) const {
	return last_name;
}
