#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "member.h"

#include <string>
#include <vector>

#include "party_member.h"

class Customer : public Member {
	public:
		Customer(std::string const first_name, std::string const last_name, std::vector<PartyMember> party, std::string const destination, bool const is_fast_lane);
		std::vector<PartyMember> get_party(void) const;
		int get_party_size(void) const;
		std::string get_destination(void) const;
		bool operator<(Customer const &r_customer) const;
	private:
		std::vector<PartyMember> party;
		int party_size;
		std::string destination;
		bool is_fast_lane;
};

#endif // CUSTOMER_H
