#ifndef BOGIE_H
#define BOGIE_H

#include <string>
#include <vector>

#include "member.h"

class Bogie {
	public:
		Bogie(std::string const &name, int const max_capacity);
		void add_member(Member const &member);
		std::string get_name(void) const;
		int get_occupied_seats(void) const;
		int get_max_capacity(void) const;
		std::string get_bogie_information(void) const;
	private:
		std::string name;
		std::vector<std::string> members;
		int occupied_seats;
		int max_capacity;
};

#endif // BOGIE_H
