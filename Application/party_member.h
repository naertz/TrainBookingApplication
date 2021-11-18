#ifndef PARTYMEMBER_H
#define PARTYMEMBER_H

#include <string>

class PartyMember {
	public:
		PartyMember(std::string const first_name, std::string const last_name, unsigned int const age);
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		int get_age(void) const;
	private:
		std::string first_name;
		std::string last_name;
		unsigned int age;
};

#endif // PARTYMEMBER_H
