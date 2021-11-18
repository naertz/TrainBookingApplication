#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include "party_member.h"

class Customer {
	public:
		Customer(std::string const first_name, std::string const last_name, std::vector<PartyMember> party, std::string const destination);
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::vector<PartyMember> get_party(void) const;
		std::string get_destination(void) const;
	private:
		std::string first_name;
		std::string last_name;
		std::vector<PartyMember> party;
		std::string destination;
};

#endif // CUSTOMER_H
