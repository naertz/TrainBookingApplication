#include "party_member.h"

/****************/
/* Constructors */
/****************/

PartyMember::PartyMember(std::string const first_name, std::string const last_name, unsigned int const age)
  : first_name(first_name)
  , last_name(last_name)
  , age(age) { }

/*************/
/* Accessors */
/*************/

std::string PartyMember::get_first_name(void) const {
	return first_name;
}

std::string PartyMember::get_last_name(void) const {
	return last_name;
}

int PartyMember::get_age(void) const {
	return age;
}
