#include "customer.h"

/****************/
/* Constructors */
/****************/

Customer::Customer(std::string const first_name, std::string const last_name, std::vector<PartyMember> const party, std::string const destination)
  : first_name(first_name)
  , last_name(last_name)
  , party(party)
  , destination(destination) { }

/*************/
/* Accessors */
/*************/

std::string Customer::get_first_name(void) const {
	return first_name;
}

std::string Customer::get_last_name(void) const {
	return last_name;
}

std::vector<PartyMember> Customer::get_party(void) const {
	return party;
}

std::string Customer::get_destination(void) const {
	return destination;
}
