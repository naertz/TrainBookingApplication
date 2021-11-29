#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
	public:
		Member(std::string const &first_name, std::string const &last_name);
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
	private:
		std::string first_name;
		std::string last_name;
};

#endif // MEMBER_H
