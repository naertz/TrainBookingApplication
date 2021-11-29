#include "bogie.h"

/****************/
/* Constructors */
/****************/

Bogie::Bogie(std::string const &name, int const max_capacity)
  : name(name)
  , occupied_seats(0)
  , max_capacity(max_capacity == 0 ? 1 : max_capacity) {
	for (int i = 0; i < max_capacity; ++i) {
		members.push_back("Empty");
	}
}

/************/
/* Mutators */
/************/

void Bogie::add_member(Member const &member) {
	if (occupied_seats + 1 <= max_capacity) {
		members[occupied_seats] = member.get_first_name() + " " + member.get_last_name();
		occupied_seats += 1;
	}
}

/*************/
/* Accessors */
/*************/

std::string Bogie::get_name(void) const {
	return name;
}

int Bogie::get_occupied_seats(void) const {
	return occupied_seats;
}

int Bogie::get_max_capacity(void) const {
	return max_capacity;
}
