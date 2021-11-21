#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include "party_member.h"

class Customer {
	public:
		Customer(std::string const first_name, std::string const last_name, std::vector<PartyMember> party, std::string const destination, bool const is_fast_lane);
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::vector<PartyMember> get_party(void) const;
		std::string get_destination(void) const;
		bool operator<(Customer const &r_customer) const;
	private:
		std::string first_name;
		std::string last_name;
		std::vector<PartyMember> party;
		std::string destination;
		bool is_fast_lane;
};

#endif // CUSTOMER_H
