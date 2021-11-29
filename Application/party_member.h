#ifndef PARTYMEMBER_H
#define PARTYMEMBER_H

#include "member.h"

#include <string>

class PartyMember : public Member {
	public:
		PartyMember(std::string const first_name, std::string const last_name, unsigned int const age);
		int get_age(void) const;
	private:
		unsigned int age;
};

#endif // PARTYMEMBER_H
