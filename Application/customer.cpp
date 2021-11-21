#include "customer.h"

/****************/
/* Constructors */
/****************/

Customer::Customer(std::string const first_name, std::string const last_name, std::vector<PartyMember> party, std::string const destination, bool const is_fast_lane)
  : first_name(first_name)
  , last_name(last_name)
  , destination(destination)
  , is_fast_lane(is_fast_lane) {
	// Loop through each party member in the vector (n - 1) times.
	for (unsigned int i = 1; i < party.size(); ++i) {
		// Get the current party member at index i.
		PartyMember current_party_member = party[i];
		// Declare the previous index.
		int previous;
		// Continue swapping party members with ages greater than the current party member's age until the current party member's age is greater than the party member's age before it or the first index is met.
		for (previous = i - 1; party[previous].get_age() > current_party_member.get_age() && previous >= 0; --previous) {
			// Change the current party member to the previous party member.
			party[previous + 1] = party[previous];
		}
		// Replace the previous party member with the current stored party member.
		party[previous + 1] = current_party_member;
	}
	this->party = party;
}

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

/**********************/
/* Operator Overloads */
/**********************/

bool Customer::operator<(Customer const &r_customer) const {
	return is_fast_lane < r_customer.is_fast_lane;
}
