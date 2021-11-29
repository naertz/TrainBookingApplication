#include "party_member.h"

/****************/
/* Constructors */
/****************/

PartyMember::PartyMember(std::string const first_name, std::string const last_name, unsigned int const age)
  : Member(first_name, last_name)
  , age(age) { }

/*************/
/* Accessors */
/*************/

int PartyMember::get_age(void) const {
	return age;
}
